// Author: Johnny Nguyen
// Email: johnnynguyenha@csu.fullerton.edu
// CPSC223C
// March 13th, 2024 8:12 PM
// Tokenizer
// Purpose: Make a C language program that will read a text file and seperate the chars from the string.
// The program will ask the user to input the name of a text file. Then, the program will check if it exists, and then if it does, open it.
// If it does not exist, then the program will ask the user to input the name again. Afterwards, the program will display the number
// of character that are in the file. Then, the program will ask for user input on a string to seperate the text file. 
// The program will seperate the text from the input, and put the tokens into a 2D array. Then, it will be printed.
// Afterwards, the program will display the number of tokens and save the array to a file named toys.tok.
// Developed: MacOS Sonoma 14.2
// Tested: MacOS Sonoma 14.2
// Compile: gcc -c -Wall -m64 -no-pie -o array.o assignment3.c -std=c17 -lm

#include "stdio.h"
#include "time.h"
#include <string.h>
#include <stdlib.h>


int main(int argc, char* argv[])
{
    char filename[80] = "";
    char seperator[30] = "";
    char tokens[100][100];
    char *token;
    int row = 0;
    int *col_sizes;
    char **tokens2;

    FILE *fp;
    printf("===== Begin execution ==========\n");
    printf("Welcome to Tokenizer brought to you by Johnny Nguyen.\n");
    printf("Please enter the name of your file: ");
    scanf("%79s", filename); 
    fp = fopen(filename, "r"); // open the file and store it into fp variable
    while (fp == NULL){ //while loop is used to keep asking for the correct file if it doesn't exist
        printf("\nSorry. File was not found. Try again.");
        printf("\nPlease enter the name of your file: ");
        scanf("%s", filename);
        fp = fopen(filename, "r");
    }
    printf("\nThe file has been opened with read permission.\n");
    fseek(fp, 0, SEEK_END);
    int size = ftell(fp) + 1; //set the size of the file using fseek
    fseek(fp, 0, SEEK_SET);
    printf("The file contains %i chars.", size);
    printf("\nThe file has been copied to a one-dimensional array and all newlines have been replaced by the space character.");
    int index = 0;
    char str[size]; // character array that will hold the values of the text file.
    char d[1] = "";
    while(EOF != (d[0] = fgetc(fp))){ // while loop that will copy each value from the file into the array.
        str[index] = d[0];
        index++;
        if (d[0] == '\n'){ //adds the newline character back into the array so we can print out the lines correctly later on and ensure the proper amount of characters.
            index++;
            str[index] = '\0';
        }
    }
    printf("\nThe first 32 bytes of the one-dimensional array are:\n");
    for (int i = 0; i < 32; i++){ // print the first 32 bytes
        printf("%c", str[i]);
    }
    printf("\nEnter some characters for the separator string and press enter: ");
    scanf("%29s", seperator); // get input for the seperator
    printf("\nThe tokens were found and placed into a two-dimensional array of char. Here are the contents of the token array in forward order.\n");
    token = strtok(str, seperator); // use strtok function to split up the array
    while(token != NULL) {
        if (strlen(token) > 0 && strspn(token, " \t\r\n") < strlen(token)) {
            if (token[strlen(token) - 1] == '\n') {
                token[strlen(token) - 1] = '\0';
            }
            printf("%s\n", token); //printing each token
            int len = strlen(token);
            strcpy(tokens[row], token); // storing each token in a two dimensional array
            row++;
        }
        token = strtok(NULL, seperator); //token and seperator
    }
    printf("\nNumber of tokens is %d", row);
    printf("\nThe array of tokens has been written to a file named toys.tok. It is generally called the token file.");
    printf("\nYou may view the token file by entering the command 'cat toys.tok'.");
    col_sizes = (int*) malloc(row * sizeof(int)); // using malloc in order to get a variable column amount
    if (col_sizes == NULL) {
        printf("Memory allocation error!");
        return 1;
    }

    tokens2 = (char **) malloc(row * sizeof(char *)); //malloc againt o get variable column size
    if (tokens2 == NULL){
        printf( "Memory allocation error!" );
        free(col_sizes);
        return 1;
    }
    for (int i = 0; i < row; i++) { //create column sizes baed on length of string in the rows
        int len = strlen(tokens[i]);
        col_sizes[i] = len;
        tokens2[i] = (char *) malloc(len * sizeof(char));
        if(tokens2[i] == NULL) {
            printf("Error: Memory Allocation failed");
            for(int j = 0; j < i; j++){
                free(tokens2[j]);
            }
            free(col_sizes);
            free(tokens2);
            return 1;
        }
        strcpy(tokens2[i], tokens[i]); //copy tokens
    }
    FILE *tokFileWrite = fopen("toys.tok", "w"); // create toys.tok since it doesn't exist
    for (int i = 0; i < row; i++) {
        fprintf(tokFileWrite, "%s\n", tokens[i]); //print the tokens to the new file
        }
    fclose(tokFileWrite);
    FILE *tokFile = fopen("toys.tok", "r");
    fseek(tokFile, 0, SEEK_END);
    int tokSize = ftell(tokFile);
    fclose(tokFile);
    printf("\nThe file size of toys.tok is %d bytes.", tokSize); // The file size is reported correctly.
    printf("\n===== End execution ==========\n");
    }

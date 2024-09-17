# Tokenizer

# Author: Johnny Nguyen
# Email: johnnynguyenha@csu.fullerton.edu
# Date: March 13th, 2024

# Overview
The Tokenizer is a C language program that reads a text file, separates its characters based on a user-defined string, and stores the resulting tokens into a 2D array. The program also outputs the number of characters in the file, the number of tokens, and saves the tokenized output to a file named toys.tok. The program will ask the user to input the name of a text file. Then, the program will check if it exists, and then if it does, open it. If it does not exist, then the program will ask the user to input the name again. Afterwards, the program will display the number of character that are in the file. Then, the program will ask for user input on a string to seperate the text file. The program will seperate the text from the input, and put the tokens into a 2D array. Then, it will be printed. Afterwards, the program will display the number of tokens and save the array to a file named toys.tok.

# Features
File Input: User specifies the name of the text file to read.  
Error Handling: Program will keep asking for the file name until a valid file is provided.  
Character Counting: Displays the number of characters in the input file.  
String Tokenization: Splits the contents of the file based on a user-defined separator string.  
Token Storage: Stores tokens in a dynamically allocated 2D array.  
File Output: Saves the tokens to a file named toys.tok and reports the size of this file.  

# Compiling
Compile using the command ./compile.sh in terminal

# Example
![image](https://github.com/user-attachments/assets/9daeb3f6-6e13-414c-8935-77716dfb903a)

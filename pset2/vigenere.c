/*  
    James Tully
    CS50
    PSET2
    vigenere.c
*/

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    // Declare variables
    string key;
    string phrase;
    int key_index = 0;
    int key_letter;
    
    // Be sure the user inputs a single number as a command line argument. 
    if(argc != 2){
        printf("Please enter a single number as a command line argument.\n");
        return 1;
    }
    
    for(int i = 0; i < strlen(argv[1]); i++){
        if(!isalpha(argv[1][i])){
            printf("Please enter a single number as a command line argument.\n");
            return 1;
        }
    }
    
    // Store the key
    key = argv[1];
    
    // Get the phrase to be encrypted from the user.
    phrase = GetString();
    
    // Cycle through the characters in the phrase string. 
    for (int i = 0, n = strlen(phrase); i < n; i++){
        
        // Force all letters to have the same index.
        key_letter = tolower(key[key_index]) - 97;
        
        // If not an alpha-numeric character, print unmodified character.
        if(!isalpha(phrase[i])){
            printf("%c", phrase[i]);
        
        // Rotate uppercase letters    
        }else if(isupper(phrase[i])){
                printf("%c", ((((phrase[i] - 65) + key_letter) % 26)) + 65);
                key_index++;
                key_index = key_index % strlen(key);
        // Rotate lowercase letters.
        }else{
            printf("%c", ((((phrase[i] - 97) + key_letter) % 26)) + 97);
                key_index++;
                key_index = key_index % strlen(key);
            }

    }

    
    //Clean up and end. 
    printf("\n");
    
    return 0;
    
}
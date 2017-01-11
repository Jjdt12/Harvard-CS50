/*  
    James Tully
    CS50
    PSET2
    caesar.c
*/

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    // Declare variables
    int rot;
    string phrase;
    
    // Be sure the user inputs a single number as a command line argument. 
    if(argc != 2){
        printf("Please enter a single number as a command line argument.\n");
        return 1;
    }
    
    // Store the rotational value for the cipher.
    rot = atoi(argv[1]);
    
    //Get the phrase to be encrypted form the user.
    phrase = GetString();
    
    //Cycle through the characters in the phrase string. 
    for (int i = 0, n = strlen(phrase); i < n; i++){
        
        //Rotate uppercase letters.
        if(isupper(phrase[i])){
        printf("%c", ((((phrase[i] - 65) + rot) % 26)) + 65);
        }
        //Rotate lowercase letters.
        else if(islower(phrase[i])){
        printf("%c", ((((phrase[i] - 97) + rot) % 26)) + 97);
        }
        //Do nothing for non-alpha characters.
        else{
            printf("%c", phrase[i]);
        }
        
    }
    
    //Clean up and end. 
    printf("\n");
    
    return 0;
    
}
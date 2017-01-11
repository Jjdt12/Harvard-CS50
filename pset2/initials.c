/*
    James Tully
    CS50
    PSET2
    initials.c
*/

#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    
    // Request the users name. 
    printf("Name: ");
    string name = GetString();
    
    // Print the first character of their intials. 
    printf("%c",toupper(name[0]));
    
    // Cycle through the rest of their name printing each of their initials. 
    for(int i = 0; i <= strlen(name); i++){
        
        if(name[i] == ' ' && name[i+1] != '\0'){
            printf("%c",toupper(name[i+1]));
        }
    }
    
    // Clean up.
    printf("\n");
    return 0;
}
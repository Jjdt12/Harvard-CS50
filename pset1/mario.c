/*  
    James Tully
    CS50
    PSET1
    mario.c
*/

include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Declare variables
    int height = 0;
    
    // Make sure user input it correct
    do{
        printf("Height: ");
        height = GetInt();
    }while(height > 23 || height < 0);
    
    // Create pyramid. 
    for(int i = 0; i < height; i++){
        
        // Print required blank spaces.
        for (int j = 0; j < height - i - 1; j ++){
            printf("%s", " ");
        }
        
        // Print required # characters. 
        for (int n = 0; n < i + 2; n++ ){
            printf("%s", "#");
        }
        
        printf("\n");
    }
}
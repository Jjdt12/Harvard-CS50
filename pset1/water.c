/*  
    James Tully
    CS50
    PSET1
    water.c
*/

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Declare variables.
    int min;
    int bot;
    
    // Request user input.
    printf("minutes: ");
    min = GetInt();
    
    // Determain total bottles.
    bot = min * 12;
    
    // Display total bottles.
    printf("bottles: %i\n", bot);
    
}
/*  
    James Tully
    CS50
    PSET1
    greedy.c
*/

#include <stdio.h>
#include <cs50.h>
#include <math.h>

// Declare constants.
#define QUARTER 25
#define DIME 10
#define NICKLE 5
#define PENNY 1

int main(void)
{
    // Declare variables.
    int change = 0;
    int count  = 0;

    // Function prototype
    int amount();
 
    // Make sure user inputs a valid number. 
    do{
        
        printf("Change owed: ");
        change = (int)round(GetFloat() * 100);
        
    }while (change <= 0);

    // Call amount() function.
    count = amount(count, change);

    // Print the total amount of coins returned from amount().
    printf("%i\n", count);
    
}



//Function to determine the amount of coins used. 
int amount(count, change){

    count += change / QUARTER;
    change = change % QUARTER;

    count += change / DIME;
    change = change % DIME;

    count += change / NICKLE;
    change = change % NICKLE;

    count += change / PENNY;
    change = change % PENNY;

return count;
}
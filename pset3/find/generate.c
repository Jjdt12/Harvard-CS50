/**
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constant
#define LIMIT 65536

int main(int argc, string argv[])
{
    // Check if user inputs correct command line arguments. 
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    // Conver the first user-supplied command line argument to an integer
    // and store it in variable n. 
    int n = atoi(argv[1]);

    // If the user inputs two command line arguments, use their second argument
    // to seed drand48(). 
    if (argc == 3)
    {
        srand48((long int) atoi(argv[2]));
    }
    // If the user inputs one command line argument use the computers clock
    // to seed drand48(). 
    else
    {
        srand48((long int) time(NULL));
    }

    // Print out requested amount (argv[1]) of random numbers 
    // generated by seeded drand48(). 
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}
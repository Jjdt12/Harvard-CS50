/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

bool search_r();

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    return search_r(value, values, n);
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    for(int j = 0; j < n; j++){
        
        for(int i = 0; i < n - 1; i++){
            
            if (values[i+1] < values[i]){
                
                int swap = 0;
                swap = values[i];
                values[i] = values[i+1];
                values[i+1] = swap;
                
            }
        }
    }
    return;
}

bool search_r(int value, int values[], int n){
    
    int max = n - 1;
    int min = 0;
    
    while(max >= min){
        int mid = (min + max) / 2;
        
        if(values[mid] == value){
            return true;
            
        }else if(values[mid] > value){
            max = mid - 1;
            
        }else{
            min = mid + 1;
            
        }
    }
    
    return false;
}
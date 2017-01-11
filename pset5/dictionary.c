/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


#include "dictionary.h"

#define HASHTABLE_SIZE 65536

typedef struct node
{
    char word[LENGTH+1];
    struct node* next;
}node;

int words;

node* hashtable[HASHTABLE_SIZE] = {NULL};

int hashing_function(char* word){
    unsigned int hash = 0;
    for (int i = 0, n = strlen(word); i < n; i++){
        hash = (hash << 2) ^ word[i];
    }
        return hash % HASHTABLE_SIZE;
}


/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // TODO
    
    int length = strlen(word);
    char *copy = malloc(length);
    
    for(int i = 0; i < length; i++){
        copy[i] = tolower(word[i]);
    }
        
        copy[length] = '\0';
        
        int index = hashing_function(copy);
        
        node* entry = hashtable[index];
        
        if(entry){
            node* cursor = entry;
            
            while(cursor->next != NULL){
                if(strcmp(copy, cursor->word)==0){
                    return true;
                }
                
                cursor = cursor->next;
            };
            
            if(strcmp(copy, cursor->word) == 0){
                return true;
            }
            
                cursor = cursor->next;
        }
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // TODO
    
    FILE* fp = fopen(dictionary, "r");
    
    if(fp == NULL){
        printf("Could not open %s. \n", dictionary);
        return false;
    }
    
    char buffer[LENGTH+2];
    
    while(fgets(buffer, sizeof(buffer), fp)){
        
        buffer[strlen(buffer) - 1] = '\0';
        
        node* temp = malloc(sizeof(node));
        
        strncpy(temp->word, buffer, LENGTH + 1);
        temp->next = NULL;
        
        int index = hashing_function(buffer);
        
        if(hashtable[index] == NULL){
            hashtable[index] = temp;
        }else{
            node* cursor = hashtable[index];
            
            while(cursor->next != NULL)
            {
                 cursor = cursor->next;
            }
            
            cursor->next = temp;
        }
        words++;
    }
    
    fclose(fp);
    
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return words;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    
    for(int i = 0; i < HASHTABLE_SIZE; i++){
        node* cursor = hashtable[i];
        if(cursor){
            node* temp = cursor->next;
            
            free(cursor);
            
            cursor = temp;
        }
    }
    return true;
}

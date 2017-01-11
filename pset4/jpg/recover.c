/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdio.h>
#include <stdint.h> //Allows us to use uint8_t
#include <string.h> // Allows us to use memcmp

int main(int argc, char* argv[])
{
    // TODO
    char* cardFile = "card.raw";
    int count = 0;
    int open = 0;
    
    // Create check arrays to use later to check for start of .jpg of the correct 
    //size in case different systems have different variable sizes
    uint8_t check_1[4] = {0xff, 0xd8, 0xff, 0xe0}; // jpg start bytes 1 or
	uint8_t check_2[4] = {0xff, 0xd8, 0xff, 0xe1}; // jpg start bytes 2 
	uint8_t check[4];
	
	// Create read file pointer to card.raw	
    FILE* CARD_DATA = fopen(cardFile, "r");
    
    // Create a file pointer for output file
    FILE* outFile; 


    // Some balogna I didn't need that I thought I did when I began the pset
    //fseek(CARD_DATA, 0L, SEEK_END);
    
    //int cardLength = ftell(CARD_DATA);
    
    //fseek(CARD_DATA, 0, SEEK_SET);
    
    // Create our buffer and read 512 bytes of information from card.raw into it
    uint8_t buff[512];
    fread(buff, 512, 1, CARD_DATA);
    
    // While able to itterate over data, do so
    while(fread(buff, 1, 512, CARD_DATA)){
            
        // Put the first 4 bytes of data into our check array
        for(int c = 0; c < 4; c++){
            check[c] = buff[c];}
                    
        // Compare our check arrays to see if we have found a .jpg
        if((memcmp(check, check_1, 4)) == 0 || (memcmp(check, check_2, 4)) == 0){
                        
            //If we have found a jpg, create a file
            char title[8];
            sprintf(title, "%03d.jpg", count);
                            
            // If there is no open file, open a and write to a file. 
            if(open == 0)
            {
                outFile = fopen(title, "w");
                fwrite(buff, sizeof(buff), 1, outFile);
                open = 1;
            }
            // If there is an open file, close it and open a new one. 
            if(open == 1)
            {
                fclose(outFile);
                outFile = fopen(title, "w");
                fwrite(buff, sizeof(buff), 1, outFile);
                count++;
            }
            // If no new jpg found, continue writing to current open jpg file. 
        }else if(open == 1){
            fwrite(buff, sizeof(buff), 1, outFile);
        }
    }

// Close files
if(outFile)
fclose(outFile);

fclose(CARD_DATA);
    
    // Qapla'
    return 0;
}

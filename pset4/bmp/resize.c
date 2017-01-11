/**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    
    // ensure proper usage
        if (argc != 4)
        {
            printf("Usage: ./resize n infile outfile\n");
            return 1;
        }


    // remember filenames
    int n = atoi(argv[1]);
    char* infile = argv[2];
    char* outfile = argv[3];
    
    // Verify factor n is in the correct range. 
    if(n > 100 || n < 1){
        printf("N must be greater then 0 and less then 100.\n");
    }

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    //Create outfiles headers
    BITMAPFILEHEADER fof = bf;
    BITMAPINFOHEADER iof = bi; 
    
    iof.biWidth *= n;
    iof.biHeight *= n;
     
    // determine padding for scanlines
    int padding_in =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int padding_out = (4 - (iof.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    iof.biSizeImage = (iof.biWidth * sizeof(RGBTRIPLE) + padding_out) * abs(iof.biHeight);
    fof.bfSize = fof.bfSize - bi.biSizeImage + iof.biSizeImage;
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&fof, sizeof(fof), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&iof, sizeof(iof), 1, outptr);
    
    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        //New lines for resize value
        for (int h = 0; h < n; h++)
        {
            // Iterate over pixels in scanline
            for (int j = 0; j < bi.biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
            
                // write RGB triple to outfile
                for(int z = 0; z < n; z++){
                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }
            
            // Add padding.
            for (int k = 0; k < padding_out; k++){
                fputc(0x00, outptr);
                }
            // Return to beginning of line.
            if(h < n - 1){
                fseek(inptr, -bi.biWidth * sizeof(RGBTRIPLE), SEEK_CUR);
            }
        }
            //skip over padding, if any
            fseek(inptr, padding_in, SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}

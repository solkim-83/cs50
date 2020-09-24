#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    
    //check the input and print error to ensure that the method can run well
    if (argc != 2)
    {
        fprintf(stderr, "Usage: recover infile\n");
        return 1;
    }

    //open input file 
    char *inputfile = argv[1];
    FILE *file = fopen(inputfile, "r");
    if (file == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", inputfile);
        return 2;
    }

    unsigned char buffer[BLOCK_SIZE]; //create buffer
    int jpg_found = 0; //tallies the number of images/ jpg found 
    int filetotal = 0; //tallies the total number of files put as inputs 
    FILE *picture = NULL;

    while (fread(buffer, BLOCK_SIZE, 1, file) == 1)
    {
        //based on the first 4 bytes of the buffer
        //proceeed with the method if the condition is met

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xe0) == 0xe0)
        {
            if (jpg_found == 1)
            {
                fclose(picture);
            }
            else
            {
                jpg_found = 1;
            }

            char filename[8];
            sprintf(filename, "%03d.jpg", filetotal);
            picture = fopen(filename, "a");
            filetotal += 1;
        }

        if (jpg_found == 1)
        {
            fwrite(&buffer, BLOCK_SIZE, 1, picture);
        }
    }

    //close the files 
    fclose(file);
    fclose(picture);

    return 0;

}

#include <cs50.h>
#include <stdio.h>
#include <stdint.h>

typedef uint8_t  BYTE;



int main(int argc, string argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    //Open memory card file
    FILE *inptr = fopen(argv[1], "r");

    //Check if the file exist
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open .\n");
        return 2;
    }

    char filename [10] ;
    BYTE buffer[512];
    int counter = 0;
    FILE *img;
    bool found = false;

    //read till the end of the file
    while (fread(&buffer,sizeof(buffer),1,inptr) == 1 )
    {

        //check the jpg signature
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {

            if (found == false)
            {
                //found a new pic
                found = true;
            }
            else
            {
                //close the old one
                fclose(img);
            }

            sprintf(filename,"%03i.jpg", counter);
            img = fopen(filename,"w");
            counter ++;

        }
        if (found == true)
        {
            fwrite(&buffer, sizeof(buffer), 1, img);

        }

    }

    //close the file
    fclose(inptr);
}
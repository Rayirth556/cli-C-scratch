// From scratch implementation of the "touch" command-line argument in C-language
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <utime.h>
#include <time.h>

int main(int argc, char* argv[])
{
    if (access(argv[1], F_OK) == 0)
    {
        struct utimbuf new_times;
        new_times.actime = time(NULL);
        new_times.modtime = time(NULL);  
        if(utime(argv[1], &new_times) != 0)
        {
            perror("Error updating timestamps");
            return 1;
        }
        printf("Updated timestamps for %s\n", argv[1]);
    }
    else
    {
        FILE* fp; 
        fp = fopen(argv[1], "w");
        if(fp == NULL)
        {
            perror("Error creating file!");
            return 1;
        }
        fclose(fp);
        printf("\nFile %s was created.\n", argv[1]);
    }
    return 0;
}
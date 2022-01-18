#include "main.h"

int validate_arguments(int argc, char* argv[])
{
        if (argc != 3)
        {
                printf("Must provide demographics file and command file.\n");
                return 0;
        }

        return 1;
}

FILE* opencheckfile(char* string, char* mode)
{
        FILE* fp = fopen(string, mode);
        if (fp == NULL)
        {
                printf("Unable to open %s file.\n", string);
                fclose(fp);
                return NULL;
        }

        return fp;
}

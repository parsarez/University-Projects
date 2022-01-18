#include "main.h"

char* remove_quotes(char* s1) {
        size_t len = strlen(s1);
        if (s1[0] == '"' && s1[len - 1] == '"') {
                s1[len - 1] = '\0';
                memmove(s1, s1 + 1, len - 1);
        }
        return s1;
}

int countLines(FILE* fp)
{
        fseek(fp, 0, SEEK_SET);

        char *line1 = NULL;
        size_t size1;
        ssize_t num1;

        int count = 0;

        while ((num1 = getline(&line1, &size1, fp)) >= 0)
        {
                count++;
        }

        fseek(fp, 0, SEEK_SET);
        free(line1);

        return count;
}

void printLos(char** los, int nofelements)
{
        printf("\n");

        int j = 0;
        int i;
        for(i=0; i< nofelements; i++)
        {
                if (j == 5)
                {
                        j = 0;
                        printf("\n");
                }
                j++;
                printf("%d", i);
                printf("[%s] ", los[i]);
        }

        printf("\n");

        return;
}

void printLosuntilNULL(char** los)
{
        printf("\n");

        int i = 0;
        while(los[i] != NULL)
        {
                printf("%d", i);
                printf("[%s] ", los[i]);
                i++;
        }

        printf("\n");

        return;
}

void removenewline(char* string)
{

        while (*string != '\0')
        {
                if (*string == '\n')
                {
                        *string = '\0';
                }
                string++;
        }

        return;
}

char** newlos(int length, char* string, char* c)
{
        //takes in a string and splits that string into
        //a char** split up by the given delimiter
        char** los = malloc((length+1) * sizeof(char*));

        char *found;
        int i = 0;

        while((found = strsep(&string, c)) != NULL)
        {
                char* newstring = strdup(found);
                newstring = remove_quotes(newstring);
                los[i] = newstring;
                i++;
        }
        los[i] = NULL;
        i--;
        removenewline(los[i]);
        remove_quotes(los[i]);

        return los;
}

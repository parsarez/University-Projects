#include "main.h"

int fieldselect(char** headerslist, char* string)
{
        int i = 0;

        while (headerslist[i] != NULL)
        {
                if (strcmp(string, headerslist[i]) == 0)
                {
                        return i;
                }
                i++;
        }

        printf("ERROR FINDING THAT COLUMN HEADER.\n");
        return 999;
}

int commandselect(char* string)
{
        int x;
        if (strcmp(string, "display") == 0)
        {
                x = 0;
                return x;
        }
        else if(strcmp(string, "filter") == 0)
        {
                x = 1;
                return x;
        }
        else if(strcmp(string, "population") == 0)
        {
                x = 2;
                return x;
        }
        else if(strcmp(string, "population-total") == 0)
        {
                x = 3;
                return x;
        }
        else if(strcmp(string, "filter-state") == 0)
        {
                x = 4;
                return x;
        }
        else if(strcmp(string, "percent") == 0)
        {
                x = 5;
                return x;
        }

        printf("What the fuck is that command?\n");
        return 99;
}

int main(int argc, char* argv[])
{
        printf("\n");
        //validating arguments
        if (validate_arguments(argc, argv) == 0)
        {
                return 0;
        }
        //Opening file for reading
        FILE *csv = opencheckfile(argv[1], "r");
        FILE *commandfile = opencheckfile(argv[2], "r");
        if (csv == NULL || commandfile == NULL)
        {
                printf("ERROR WITH FILES.\n");
                return 0;
        }

        //loaded char** of column headers
        char** headers = createheaders(csv, LENGTH);

        //printLosuntilNULL(headers);
        //printf("\n");

        //loaded list of nodes
        linklist* parsalist = newlinklist();
        loadCSV(csv, parsalist);
        //display(parsalist);

        //loaded list of commands
        linklist* commandlist = newlinklist();
        addcommands(commandlist, commandfile);
        //printlinklist(commandlist);

        int flag = 0;
        node* ptr = commandlist->head;
        while (ptr != NULL)
        {
                if (flag == 0)
                {
                  printf("-%d records loaded-\n", parsalist->size);
                  flag = 1;
                }


                printf("---------------------------------------------");
                switch(commandselect(ptr->los[0]))
                {
                case 0:
                {

                        //printf("-Executing command %s-\n", ptr->los[0]);
                        display(parsalist);
                        printf("\n");
                        break;
                }

                case 1:
                {
                        //printf("-%d records loaded-\n", parsalist->size);
                        //printf("-Executing command %s-\n", ptr->los[0]);
                        float temp2 = atof(ptr->los[3]);
                        parsalist = filter(parsalist, headers, ptr->los[1],
                                           ptr->los[2], temp2);
                        printf("\n");
                        break;
                }

                case 2:
                {
                        //printf("-%d records loaded-\n", parsalist->size);
                        //printf("-Executing command %s-\n", ptr->los[0]);
                        float answer = population(parsalist, headers, ptr->los[1]);
                        printf("\n2014 <%s> population: %f\n", ptr->los[1], answer);
                        printf("\n");
                        break;
                }

                case 3:
                {
                        //printf("-%d records loaded-\n", parsalist->size);
                        //printf("-Executing command %s-\n", ptr->los[0]);
                        int answer = populationtotal(parsalist);
                        printf("\n2014 Population: %d\n\n", answer);
                        printf("\n");
                        break;
                }

                case 4:
                {
                        //printf("-%d records loaded-\n", parsalist->size);
                        //printf("-Executing command %s-\n", ptr->los[0]);
                        parsalist = filterstate(parsalist, ptr->los[1]);
                        printf("\n");
                        break;
                }

                case 5:
                {
                        //printf("-%d records loaded-\n", parsalist->size);
                        //printf("-Executing command %s-\n", ptr->los[0]);
                        percent(parsalist,headers, ptr->los[1]);
                        printf("\n");
                        break;
                }

                default:
                {
                        printf("That is an invalid command.\n");
                        printf("\n");
                        return 0;
                }
                }
                //printf("---------------------------------------------");
                ptr = ptr->next;
        }

        printf("\n");
        printf("Success executing the command file.\n");
        printf("\n");
        fclose(csv);
        fclose(commandfile);
        //freelinklist(commandlist);
        freelinklist(parsalist, LENGTH);
        free(headers);
        return 0;
}

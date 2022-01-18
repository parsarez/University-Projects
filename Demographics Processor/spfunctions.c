#include "main.h"

void loadCSV(FILE* fp, linklist *list)
{
        //Making sure that file pointer is not NULL
        if (fp == NULL)
        {
                printf("ERROR, FILE NOT FOUND.\n");
                return;
        }

        char * line = NULL;
        size_t len = 0;
        ssize_t read;

        //read = getline(&line, &len, fp);

        while ((read = getline(&line, &len, fp)) != -1)
        {
                char* newstring = strdup(line);
                addtoendoflist(list, newstring, ",");
        }
        free(line);

        return;
}

void display(linklist *list)
{
        node* ptr = list->head;

        while (ptr != NULL)
        {
                char** stringlist = ptr->los;
                printf("\n");
                printf("------------------------------");
                printf("%s, %s", stringlist[0], stringlist[1]);
                printf("-------------\n");
                printf("\tPopulation: %d\n", atoi(stringlist[TWENTYFOUR]));
                printf("Education\n");
                printf("\t\t>= High School: %f%%\n", atof(stringlist[6]));
                printf("\t\t>= Bachelor's: %f%%\n", atof(stringlist[5]));
                printf("\tEthnicity Percentages\n");
                printf("\t\tAmerican Indian and Alaska Native: %f%%\n", atof(stringlist[11]));
                printf("\t\tAsian Alone: %f%%\n", atof(stringlist[12]));
                printf("\t\tBlack Alone: %f%%\n", atof(stringlist[13]));
                printf("\t\tHispanic or Latino: %f%%\n", atof(stringlist[14]));
                printf("\t\tNative Hawaiian and Other Pacific Islander Alone: %f%%\n", atof(stringlist[15]));
                printf("\t\tTwo or More Races: %f%%\n", atof(stringlist[16]));
                printf("\t\tWhite Alone: %f%%\n", atof(stringlist[17]));
                printf("\t\tWhite Alone, Not Hispanic or Latino: %f%%\n", atof(stringlist[18]));
                printf("\tIncome\n");
                printf("\t\tMedian Household: %d\n", atoi(stringlist[25]));
                printf("\t\tPer Capita: %d\n", atoi(stringlist[26]));
                printf("\t\tBelow Poverty Level: %f%%\n", atof(stringlist[27]));
                printf("---------------------------------------------");
                printf("\n");
                ptr = ptr->next;
        }
return;
}

linklist* filter(linklist* list, char** headerslist, char* field, char* gorl, float number)
{

        linklist* newlist = newlinklist();
        int z = fieldselect(headerslist, field);

        if (strcmp(gorl, "ge") != 0 && strcmp(gorl, "le") != 0)
        {
                printf("\nERROR. Invalid ge or le command.\n\n");
                return newlist;
        }

        node* ptr = list->head;
        if(ptr == NULL)
        {
                printf("\nThe given list is empty.\n\n");
        }

        if (strcmp(gorl,"ge") == 0)
        {
                while(ptr != NULL)
                {
                        if (atof(ptr->los[z]) >= number)
                        {
                                copyandaddnode(newlist, ptr);
                        }
                        ptr = ptr->next;
                }

                printf("\nFilter: %s %s %f (%d entries)\n", field, gorl, number, newlist->size);
                //freelinklist(list);
                return newlist;
        }

        while(ptr != NULL)
        {
                if (atof(ptr->los[z]) <= number)
                {
                        copyandaddnode(newlist, ptr);
                }
                ptr = ptr->next;
        }

        printf("\nFilter: %s %s %f (%d entries)\n", field, gorl, number, newlist->size);
        //freelinklist(list);
        return newlist;
}

float population(linklist* list, char** headerslist, char* field)
{
        int z = fieldselect(headerslist, field);
        if (list->head == NULL)
        {
                printf("\nThe given list is empty.\n\n");
        }

        node* ptr = list->head;

        float allsub = 0;

        while(ptr != NULL)
        {
                float x = atof(ptr->los[z]);
                float t = x/100;
                float y = atof(ptr->los[TWENTYFOUR]);
                float subpop = t * y;
                allsub += subpop;
                ptr = ptr->next;
        }

        //float totalpop = populationTotal(list);
        //float result = allsub / totalpop;
        //float percent = result * 100;

        //printf("\n2014 <%s> population: %f\n", field, allsub);
        //printf("\nThe given list is %f%% of type %d.\n\n", percent, z);

        return allsub;
}

float populationtotal(linklist* list)
{
        if (list->head == NULL)
        {
                printf("\nThe given list is empty.\n\n");
        }

        node* ptr = list->head;
        int total = 0;

        while(ptr != NULL)
        {
                //printf("%s\n", ptr->los[38]);
                float x = strtof(ptr->los[TWENTYFOUR], NULL);
                //printf("\n%f\n", x);
                total += x;
                ptr = ptr->next;
        }

        //printf("\n2014 Population: %d\n\n", total);

        return total;
}

linklist* filterstate(linklist* list, char* string)
{
        linklist* filteredlist = newlinklist();

        if (list->size == 0)
        {
                printf("The given list is empty.");
                return filteredlist;
        }
        //filters the given list down to only nodes with node->los[0] == string
        node* ptr = list->head;
        while (ptr != NULL)
        {
                if (strcmp(ptr->los[1], string) == 0)
                {
                        copyandaddnode(filteredlist, ptr);
                }
                ptr = ptr->next;
        }
        printf("\nFiltering %s nodes.\n", string);
        printf("(%d nodes)\n", filteredlist->size);

        //freelinklist(list);
        return filteredlist;
}

float percent(linklist* list, char** headerslist, char* field)
{
        float totalpop = populationtotal(list);
        float subpop = population(list, headerslist, field);
        float decimal = subpop/totalpop;
        float percent = decimal * 100;

        printf("\n2014 <[%s]> percentage: %f%%\n", field, percent);
        return decimal;
}

#include "main.h"

void addcommands(linklist* list, FILE* fp)
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

        rewind(fp);

        while ((read = getline(&line, &len, fp)) != -1)
        {
                char* newstring = strdup(line);
                addtoendoflistcommand(list, newstring);
        }
        free(line);

        return;
}

void addtoendoflistcommand(linklist* list, char* string)
{
        //creates a complete node and adds it to the Array_List
        //takes into account empty case and non empty case

        node *ptr = (node*) malloc(sizeof(node));
        mallocChecker(ptr);

        //empty case
        if (list->head == NULL)
        {
                //set Node contents to correct values
                ptr->next = NULL;
                ptr->prev = NULL;
                ptr->index = 0;
                ptr->los = newloscommand(string);

                //set ArrayList contents to correct values
                list->head = ptr;
                list->tail = ptr;
                list->size = 1;

                return;
        }
//set ArrayList contents to correct values
        list->size += 1;

//set Node contents to correct values
        ptr->next = NULL;
        list->tail->next = ptr;
        ptr->prev = list->tail;
        list->tail = ptr;

        ptr->index = list->size - 1;
        ptr->los = newloscommand(string);

        return;
}

char** newloscommand(char* string)
{
        //takes in a string and splits that string into
        //a char** split up by the given delimiter
        //ends the char** with a NULL string
        char** los = malloc(5 * sizeof(char*));

        char *found;
        char* delim = ":";
        int i = 0;

        while((found = strsep(&string, delim)) != NULL)
        {
                char* newstring = strdup(found);
                //printf("%s", found);
                los[i] = newstring;
                i++;
        }

        if (i == 1)
        {
          removenewline(los[0]);
          los[1] = NULL;
          los[2] = NULL;
          los[3] = NULL;
          los[4] = NULL;
          return los;
        }

        if (i == 2)
        {
          removenewline(los[1]);
          los[2] = NULL;
          los[3] = NULL;
          los[4] = NULL;
          return los;
        }

        if (i == 3)
        {
          removenewline(los[2]);
          los[3] = NULL;
          los[4] = NULL;
          return los;
        }

        if (i == 4)
        {
          removenewline(los[3]);
          los[4] = NULL;
          return los;
        }

        printf("ERROR IN NEWLOSCOMMAND.\n");
        return NULL;
}

char** createheaders(FILE* fp, int length)
{
        char** new = (char**)malloc(53 * (sizeof(char*)));

        new[0] = "County";
        new[1] = "State";
        new[2] = "Age.Percent 65 and Older";
        new[3] = "Age.Percent Under 18 Years";
        new[4] = "Age.Percent Under 5 Years";
        new[5] = "Education.Bachelor's Degree or Higher";
        new[6] = "Education.High School or Higher";
        new[7] = "Employment.Nonemployer Establishments";
        new[8] = "Employment.Private Non-farm Employment";
        new[9] = "Employment.Private Non-farm Employment Percent Change";
        new[10] = "Employment.Private Non-farm Establishments";
        new[11] = "Ethnicities.American Indian and Alaska Native Alone";
        new[12] = "Ethnicities.Asian Alone";
        new[13] = "Ethnicities.Black Alone";
        new[14] = "Ethnicities.Hispanic or Latino";
        new[15] = "Ethnicities.Native Hawaiian and Other Pacific Islander Alone";
        new[16] = "Ethnicities.Two or More Races";
        new[17] = "Ethnicities.White Alone";
        new[18] = "Ethnicities.White Alone, not Hispanic or Latino";
        new[19] = "Housing.Homeownership Rate";
        new[20] = "Housing.Households";
        new[21] = "Housing.Housing Units";
        new[22] = "Housing.Median Value of Owner-Occupied Units";
        new[23] = "Housing.Persons per Household";
        new[24] = "Housing.Units in Multi-Unit Structures";
        new[25] = "Income.Median Houseold Income";
        new[26] = "Income.Per Capita Income";
        new[27] = "Income.Persons Below Poverty Level";
        new[28] = "Miscellaneous.Building Permits";
        new[29] = "Miscellaneous.Foreign Born";
        new[30] = "Miscellaneous.Land Area";
        new[31] = "Miscellaneous.Language Other than English at Home";
        new[32] = "Miscellaneous.Living in Same House +1 Years";
        new[33] = "Miscellaneous.Manufacturers Shipments";
        new[34] = "Miscellaneous.Mean Travel Time to Work";
        new[35] = "Miscellaneous.Percent Female";
        new[36] = "Miscellaneous.Veterans";
        new[37] = "Population.2010 Population";
        new[38] = "Population.2014 Population";
        new[39] = "Population.Population Percent Change";
        new[40] = "Population.Population per Square Mile";
        new[41] = "Sales.Accommodation and Food Services Sales";
        new[42] = "Sales.Merchant Wholesaler Sales";
        new[43] = "Sales.Retail Sales";
        new[44] = "Sales.Retail Sales per Capita";
        new[45] = "Employment.Firms.American Indian-Owned";
        new[46] = "Employment.Firms.Asian-Owned";
        new[47] = "Employment.Firms.Black-Owned";
        new[48] = "Employment.Firms.Hispanic-Owned";
        new[49] = "Employment.Firms.Native Hawaiian and Other Pacific Islander-Owned";
        new[50] = "Employment.Firms.Total";
        new[51] = "Employment.Firms.Women-Owned";
        new[52] = NULL;

        return new;
}

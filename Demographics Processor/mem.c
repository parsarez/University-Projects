#include "main.h"

void freelos(char** los, int length)
{
        char *ptr;
        int i;
        for (i =0; i< length; i++)
        {
                ptr = los[i];
                free(los[i]);
        }
        return;
}

void freelinklist(linklist *list, int length)
{
        if (list->head == NULL)
        {
                printf("---- The given list is empty, no memory to free. ----\n");
                return;
        }

        node *ptr;
        node *ptr2;
        ptr = list->head;

        while (ptr != NULL)
        {
                ptr2 = ptr;
                freelos(ptr->los, length);
                free(ptr->los);
                ptr = ptr->next;
                free(ptr2);

        }
        return;
}

#include "main.h"

void printlinklist(linklist* list)
{
        if (list->head == NULL)
        {
                printf("---- The given list IS EMPTY and of size: %d ----\n", list->size);
                return;
        }

        printf("---- The given list is NOT EMPTY and has a size of: %d ----\n\n", list->size);
        printf("---------------------------------------------\n");

        node* ptr = list->head;
        while(ptr != NULL)
        {
                if (ptr == list->head)
                {
                        printf("[head]");
                }
                if(ptr == list->tail)
                {
                        printf("[tail]");
                }
                printf("Node[%d]\n\n", ptr->index);

                printLosuntilNULL(ptr->los);

                printf("\n");

                printf("---------------------------------------------\n");
                ptr = ptr->next;
        }
        free(ptr);
        return;
}

void mallocChecker(void *ptr)
{
        //To check if the memory was allocated and to confirm that the data has been placed within the NODE
        if (ptr == NULL)
        {
                printf("ERROR, Memory was not allocated using malloc.\n");
                free(ptr);
        }

        //printf("Memory successfully allocated using malloc.\n\n");
        return;
}


linklist* newlinklist()
{
        linklist *list = (linklist*) malloc(sizeof(linklist));
        mallocChecker(list);

        list->head = NULL;
        list->tail = NULL;
        list->size = 0;
        return list;
}

void copyandaddnode(linklist* list, node* gnode)
{
        node* ptr = (node*) malloc(sizeof(node));

        mallocChecker(ptr);

        ptr->los = gnode->los;
        ptr->index = gnode->index;

        if (list->size == 0)
        {
                list->head = ptr;
                list->tail = ptr;
                ptr->next = NULL;
                ptr->prev = NULL;
                list->size += 1;
                return;
        }

        list->size += 1;
        ptr->next = NULL;
        list->tail->next = ptr;
        ptr->prev = list->tail;
        list->tail = ptr;
        return;
}

void addtoendoflist(linklist* list, char* string, char* delim)
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
                ptr->los = newlos(LENGTH, string, delim);

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
        ptr->los = newlos(LENGTH, string, delim);

        return;
}

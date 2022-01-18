#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LENGTH 52
#define TWENTYFOUR 38
#define HIGHSCHOOL 6
#define BACHELOR 5


extern const char* operations[];

typedef struct List
{
        struct Node* head;
        struct Node* tail;
        int size;
} linklist;

typedef struct Node
{
        char** los;
        int index;
        struct Node* next;
        struct Node* prev;
} node;

//main.c
int fieldselect(char**, char*);
int commandselect(char*);


//commands.c
void addcommands(linklist*, FILE*);
void addtoendoflistcommand(linklist*, char*);
char** newloscommand(char*);
char** createheaders(FILE*, int);

//filestuff
int validate_arguments(int, char**);
FILE* opencheckfile(char*, char*);
char** newloscommand(char*);

//liststuff
void mallocChecker(void*);
linklist* newlinklist();
void copyandaddnode(linklist*, node*);
void addtoendoflist(linklist*, char*, char*);
void printlinklist(linklist*);
linklist* filterState(linklist*, char*);

//mem.c
void freelos(char**, int);
void freelinklist(linklist*, int);

//spfunctions
void loadCSV(FILE*, linklist*);
void display(linklist*);
linklist* filterstate(linklist*, char*);
linklist* filter(linklist*,char**, char*, char*, float);
float populationtotal(linklist*);
float population(linklist*,char**, char*);
float percent(linklist*, char**, char*);

//stringstuff
int countLines(FILE*);
void printLos(char**, int);
void printLosuntilNULL(char**);
void removenewline(char*);
char** newlos(int, char*, char*);
char* remove_quotes(char*);

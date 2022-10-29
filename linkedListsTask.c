#include "listMethods.h"
//#include "listStructs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    Node* head = NULL;
    head = (Node*)malloc(sizeof(Node));
    if(NULL == head){
        printf("Initialisation failed!\n");
        return -1;
    }
    head->next = NULL;

    insertStart(&head, "Ana", "Ivic", 1997);
    insertEnd(head, "Ime", "Prezime", 1998);
    insertStart(&head, "Ivo", "Anic", 1999);
    insertEnd(head, "Jure", "Horvat", 2000);
    
    printList(head->next);

    return 0;
}
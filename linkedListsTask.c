#include "listMethods.h"
//#include "listStructs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int choice = 0;
    struct Node *head = NULL;
    head = (struct Node *)malloc(sizeof(struct Node));
    if (NULL == head)
    {
        printf("Initialisation failed!\n");
        return -1;
    }
    head->next = NULL;

    insertStart(&head, "Ana", "Ivic", 1997);
    insertEnd(head, "Ime", "Prezime", 1998);
    insertStart(&head, "Ivo", "Anic", 1999);
    insertEnd(head, "Jure", "Horvat", 2000);

    do
    {
        printf("<<<<<< MENU >>>>>>\n");
        printf("\t0 - end\n");
        printf("\t1 - add person to the beginning of list\n");
        printf("\t2 - add person to the end of list\n");
        printf("\t3 - find person by last name\n");
        printf("\t4 - delete from list\n");
        printf("\t5 - print the list\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            break;
        case 1:
        {
            char name[32];
            char lastName[32];
            int yearOfBirth;
            printf("Name Lastname Birth year:\n");
            scanf("%s %s %d", &name, &lastName, &yearOfBirth);
            insertStart(&head, name, lastName, yearOfBirth);
            break;
        }
        case 2:
        {
            char name[32];
            char lastName[32];
            int yearOfBirth;
            printf("Name Lastname Birth year:\n");
            scanf("%s %s %d", &name, &lastName, &yearOfBirth);
            insertEnd(head, name, lastName, yearOfBirth);
            break;
        }
        case 3:
        {
            char lastName[32];
            printf("Lastname: ");
            scanf("%s", &lastName);
            findLName(head, lastName);
            break;
        }
        case 4:
        {
            char lastName[32];
            printf("Lastname: ");
            scanf("%s", &lastName);
            removeNode(head, lastName);
            break;
        }
        case 5:
            printList(head->next);
            break;
        default:
            break;
        }
    } while (choice != 0);

    return 0;
}
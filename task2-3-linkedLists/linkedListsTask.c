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

    /*
    insertStart(&head, "Ana", "Ivic", 1997);
    insertEnd(head, "Ime", "Prezime", 1998);
    insertStart(&head, "Ivo", "Anic", 1999);
    insertEnd(head, "Jure", "Horvat", 2000); */

    /*struct Node target = findLName(head, "Prezime");
    printf("%s %s %d", target.data.name, target.data.lastname, target.data.yearOfBirth);*/

    do
    {
        printf("<<<<<< MENU >>>>>>\n");
        printf("\t0 - end\n");
        printf("\t1 - add person to the beginning of list\n");
        printf("\t2 - add person to the end of list\n");
        printf("\t3 - find person by last name\n");
        printf("\t4 - delete by last name\n");
        printf("\t5 - print the list\n");
        printf("\t6 - add before another\n");
        printf("\t7 - add after another\n");
        printf("\t8 - sort by last name\n");
        printf("\t9 - write to file\n");
        printf("\t10 - read from file\n");
        printf("\t11 - clear list\n");

        scanf(" %d", &choice);

        //system("cls");

        switch (choice)
        {
        case 0:
            break;
        case 1:
        {
            char name[32];
            char lastname[32];
            int yearOfBirth;
            printf("Name Last name Birth year: ");
            scanf("%s %s %d", &name, &lastname, &yearOfBirth);
            if (insertStart(&head, name, lastname, yearOfBirth) == -1){
                printf("Error!\n");
                clearList(&head);
                return -1;
            }
            break;
        }
        case 2:
        {
            char name[32];
            char lastname[32];
            int yearOfBirth;
            printf("Name Last name Birth year: ");
            scanf("%s %s %d", &name, &lastname, &yearOfBirth);
            if (insertEnd(head, name, lastname, yearOfBirth) == -1){
                printf("Error!\n");
                clearList(&head);
                return -1;
            }
            break;
        }
        case 3:
        {
            char lastName[32];
            printf("Last name: ");
            scanf("%s", &lastName);
            struct Node target = findLName(head, lastName);
            printf("First name: %s; Last name: %s; Year of birth: %d\n",
                   target.data.name, target.data.lastname, target.data.yearOfBirth);
            break;
        }
        {   
            char lastName[32];
                    
            printf("Available last names: \n");
            printLNames(head);
            printf("Last name: ");
            scanf("%s", &lastName);
            removeNode(head, lastName);
            break;
        }
        case 5:
        {   
            if (NULL == head->next){
                printf("List empty!\n");
                break;
            }
            printList(head->next);
            break;
        }
        case 6:
        {
            char targetLastname[32];
            char name[32];
            char lastname[32];
            int yearOfBirth;

            printf("Name Lastname Birth year: ");
            scanf("%s %s %d", &name, &lastname, &yearOfBirth);

                    
            printf("Available last names: \n");
            printLNames(head);
            printf("\nAdd before element with last name: ");
            scanf("%s", &targetLastname);

            addBefore(head, targetLastname, name, lastname, yearOfBirth);
            break;
        }
        case 7:
        {
            char targetLastname[32];
            char name[32];
            char lastname[32];
            int yearOfBirth;

            printf("Name Last name Birth year: ");
            scanf("%s %s %d", &name, &lastname, &yearOfBirth);

            
            printf("Available last names: \n");
            printLNames(head);
            printf("Add after element with last name: ");
            scanf("%s", &targetLastname);

            addAfter(head, targetLastname, name, lastname, yearOfBirth);
            break;
        }
        case 8:
        {
            sortListByLastname(head);
            printList(head->next);
            break;
        }
        case 9:
        {
            if(writeToFile(head->next) == -1){
                printf("Error!\n");
                clearList(&head);
                return -1;
            }
            break;
        }
        case 10:
        {
            if(readFromFile(head) == -1){
                printf("Error!\n");
                clearList(&head);
                return -1;
            }
            break;
        }
        case 11:
        {
            clearList(head);
            break;
        }
        default:
            break;
        }
    } while (choice != 0);

    return 0;
}
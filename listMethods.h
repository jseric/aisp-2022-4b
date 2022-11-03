#include "listStructs.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int insertStart(struct Node **head, char nameIn[], char lastnameIn[], int yobIn)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    if (NULL == newNode)
    {
        printf("Memory allocation failed!\n");
        return -1;
    }

    strcpy(newNode->data.name, nameIn);
    strcpy(newNode->data.lastname, lastnameIn);
    newNode->data.yearOfBirth = yobIn;

    (*newNode).next = (*head)->next;
    (*head)->next = newNode;

    return 1;
}
int insertEnd(struct Node *head, char nameIn[], char lastnameIn[], int yobIn)
{
    struct Node *position = head;

    while (position->next != NULL)
    {
        position = position->next;
    }

    position->next = (struct Node *)malloc(sizeof(struct Node));
    if (NULL == position->next)
    {
        printf("Memory allocation failed!\n");
        return -1;
    }

    strcpy(position->next->data.name, nameIn);
    strcpy(position->next->data.lastname, lastnameIn);
    position->next->data.yearOfBirth = yobIn;

    position->next->next = NULL;

    return 1;
}

int printList(struct Node *position)
{
    if (NULL == position)
    {
        printf("List empty!\n");
        return 0;
    }
    while (position != NULL)
    {
        printf("First name: %s; Last name: %s; Year of birth: %d\n",
               position->data.name, position->data.lastname, position->data.yearOfBirth);
        position = position->next;
    }

    return 1;
}

int findLName(struct Node *head, char *targetLName)
{
    struct Node *current = head;

    if (NULL == current)
        return -1;

    while (current != NULL)
    {
        if (strcmp(current->data.lastname, targetLName) != 0)
        {
            printf("Person found!\n%s %s %d\n", current->data.name, current->data.lastname,
                   current->data.yearOfBirth);
            return 1;
        }
        current = current->next;
    }

    printf("Person not found.\n");
    return 0;
}

int removeNode(struct Node *head, char targetLName[])
{
    struct Node *temp;
    while (head->next != NULL)
    {
        if (strcmp(head->next->data.lastname, targetLName) != 0)
        {
            printf("Delete successful!\n");
            temp = head->next;
            head->next = temp->next;
            free(temp);
            return 2;
        }
        head = head->next;
    }
    printf("Person not found.\n");
    return 1;
}
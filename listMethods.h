#include "listStructs.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int insertStart(Node **head, char nameIn[], char lastnameIn[], int yobIn)
{
    Node *newNode;
    newNode = (Node *)malloc(sizeof(Node));
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
int insertEnd(Node *head, char nameIn[], char lastnameIn[], int yobIn)
{
    Node *position = head;

    while (position->next != NULL)
    {
        position = position->next;
    }

    position->next = (Node *)malloc(sizeof(Node));
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

int printList(Node *position)
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

int findLName(Node *head, char targetLName[])
{
    if (head == NULL)
    {
        return -1;
    }
    if (strcmp(head->next->data.lastname, targetLName))
    {
        printf("Person found!\nFirst name: %s; Last name: %s; Year of birth: %d\n", head->data.name, head->data.lastname, head->data.yearOfBirth);
        return 1;
    }
    return findLName(head->next, targetLName);
}

int removeNode(Node *head, char targetLName[])
{
    Node *temp;
    while (head->next != NULL)
    {
        if (strcmp(head->next->data.lastname, targetLName))
        {
            printf("Deletion successful!\n");
            temp = head->next;
            head->next = temp->next;
            free(temp);
        }
        head = head->next;
    }
    return 1;
}
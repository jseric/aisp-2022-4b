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

int printLNames(struct Node *position)
{
    if (NULL == position)
    {
        printf("List empty!\n");
        return 0;
    }
    position = position->next;
    while (position != NULL)
    {
        printf("%s ", position->data.lastname);
        position = position->next;
    }
    printf("\n");
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

struct Node findLName(struct Node *head, char *targetLName)
{
    struct Node temp;

    while (head != NULL)
    {
        if (strcmp(head->data.lastname, targetLName) == 0)
        {
            temp = *head;
        }
        head = head->next;
    }
    return temp;
}

struct Node findPrevious(struct Node *head, char *targetLName)
{
    struct Node temp;

    while (head != NULL)
    {
        if (strcmp(head->next->data.lastname, targetLName) == 0)
        {
            temp = *head;
        }
        head = head->next;
    }
    return temp;
}

int removeNode(struct Node *head, char targetLName[])
{
    struct Node *temp;
    while (head->next != NULL)
    {
        if (strcmp(head->next->data.lastname, targetLName) == 0)
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

void addBefore(struct Node *head, char targetLName[], char nameIn[], char lastnameIn[], int yobIn)
{
    struct Node *newNode;
    struct Node predecessor;
    struct Node targetEl;
    newNode = (struct Node *)malloc(sizeof(struct Node));

    strcpy(newNode->data.name, nameIn);
    strcpy(newNode->data.lastname, lastnameIn);
    newNode->data.yearOfBirth = yobIn;

    predecessor = findPrevious(head, targetLName);
    targetEl = findLName(head, targetLName);

    predecessor.next = newNode;
    newNode->next = &targetEl;
}

void addAfter(struct Node *head, char targetLName[], char nameIn[], char lastnameIn[], int yobIn)
{
    struct Node *newNode;
    struct Node targetEl;
    newNode = (struct Node *)malloc(sizeof(struct Node));

    strcpy(newNode->data.name, nameIn);
    strcpy(newNode->data.lastname, lastnameIn);
    newNode->data.yearOfBirth = yobIn;

    targetEl = findLName(head, targetLName);

    newNode->next = targetEl.next;
    targetEl.next = &newNode;
}

void sortListByLastname(struct Node *head)
{
    struct Node *i;
    struct Node *j;
    struct Node *jPred;
    struct Node *end = NULL;

    while (head->next != end)
    {
        i = head;
        jPred = i->next;
        j = jPred->next;

        while (j != end)
        {
            if (strcmp(jPred->data.lastname, j->data.lastname) > 0)
            {
                jPred->next = j->next;
                i->next = j;
                j->next = jPred;
            }
            else
            {
                i = jPred;
            }
            jPred = j;
            j = j->next;
        }
        end = jPred;
    }
}

int readFromFile(struct Node *head)
{

    char inputFName[32], inputLName[32], filename[32];
    int inputYoB;

    printf("Name of file to read from: ");
    scanf(" %s", filename);

    FILE *fp = fopen(filename, "r");
    if (NULL == fp)
    {
        printf("Failed to open or create file.\n");
        return -1;
    }

    while (!feof(fp))
    {
        fscanf(fp, "%s %s %d\n", &inputFName, &inputLName, &inputYoB);
        insertEnd(head, inputFName, inputLName, inputYoB);
    }

    printf("List read successfully:\n");
    printList(head->next);
    fclose(fp);
    return 1;
}

int writeToFile(struct Node *position)
{

    char filename[32] = "";

    printf("Name of file to write to: ");
    scanf(" %s", filename);

    FILE *fp = fopen(filename, "w+");
    if (NULL == fp)
    {
        printf("Failed to open or create file.\n");
        return -1;
    }

    if (NULL == position)
    {
        fprintf(fp, "List empty!\n");
        return 0;
    }
    while (position != NULL)
    {
        fprintf(fp, " %s %s %d\n",
                position->data.name, position->data.lastname, position->data.yearOfBirth);
        position = position->next;
    }

    fclose(fp);
    return 1;
}
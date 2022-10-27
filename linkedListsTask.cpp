#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
using namespace std;

typedef struct
{
    char name[32];
    char lastname[32];
    int yearOfBirth;
} Person;

typedef struct
{
    Person person;
    Node *next;
} Node;

Node newNode(char name[], char lastname[], int yearOfBirth)
{
    Node *newEl;
    newEl = (Node *)malloc(sizeof(Node));
    newEl->person.yearOfBirth = yearOfBirth;
    strcpy(newEl->person.name, name);
    strcpy(newEl->person.lastname, lastname);
    newEl->next = NULL;
    return *newEl;
}

int insertStart(Node *head, char name[], char lastname[], int yearOfBirth)
{
    Node newVal;
    newVal = newNode(name, lastname, yearOfBirth);
    head->next = &newVal;
    return 0;
}

int main()
{
    printf("test");
    return 0;
}
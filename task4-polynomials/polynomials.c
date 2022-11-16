#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _Polynomial
{
    int coefficient;
    int exponent;
} Polynomial;

struct Node
{
    Polynomial polynomial;
    struct Node *next;
};

int readPolynomialFromFile(struct Node *head)
{
    char fileName[32];
    FILE *fPolynomialStream;
    struct Node *pol;

    printf("\r\nInput file name: ");
    scanf("%s", fileName);

    fPolynomialStream = fopen(fileName, "r");

    if (fPolynomialStream == NULL)
    {
        printf("File empty!\n");
        return -1;
    }

    while (!feof(fPolynomialStream))
    {
        pol = (struct Node *)malloc(sizeof(struct Node));
        if (pol == NULL)
        {
            printf("Memory allocation failed!\n");
            return -1;
        }
        fscanf(fPolynomialStream, "%d %d", &pol->polynomial.coefficient, &pol->polynomial.exponent);
        pol->next = head->next;
        head->next = pol;
    }

    return 0;
}

int sortPolynomialsByExponent(struct Node *head)
{
    struct Node *j, *j_predecessor, *temp, *end;

    while (head->next != end)
    {
        j_predecessor = head;
        j = head->next;

        while (j->next != end)
        {
            if (j->polynomial.exponent < j->next->polynomial.exponent)
            {
                temp = j->next;
                j_predecessor->next = temp;
                j->next = temp->next;
                temp->next = j;
                j = temp;
            }
            j_predecessor = j;
            j = j->next;
        }
        end = j;
    }

    return 0;
}

int sumPolynomials(struct Node *headPol1, struct Node *headPol2, struct Node *headRes)
{
    struct Node *pol, *temp;

    while (headPol1 != NULL && headPol2 != NULL)
    {
        pol = (struct Node *)malloc(sizeof(struct Node));

        if (pol == NULL)
        {
            printf("Failed memory allocation!\n");
            return -1;
        }

        if (headPol1->polynomial.exponent > headPol2->polynomial.exponent)
        {
            pol->polynomial.coefficient = headPol1->polynomial.coefficient;
            pol->polynomial.exponent = headPol1->polynomial.exponent;
            headPol1 = headPol1->next;
        }
        else if (headPol1->polynomial.exponent < headPol2->polynomial.exponent)
        {
            pol->polynomial.coefficient = headPol2->polynomial.coefficient;
            pol->polynomial.exponent = headPol2->polynomial.exponent;
            headPol2 = headPol2->next;
        }
        else
        {
            pol->polynomial.exponent = headPol1->polynomial.exponent;
            pol->polynomial.coefficient = headPol1->polynomial.coefficient + headPol2->polynomial.coefficient;
            headPol1 = headPol1->next;
            headPol2 = headPol2->next;
        }
        pol->next = headRes->next;
        headRes->next = pol;
        headRes = headRes->next;
    }

    if (headPol1 == NULL)
        temp = headPol2;
    else
        temp = headPol1;

    while (temp != NULL)
    {
        pol = (struct Node *)malloc(sizeof(struct Node));

        if (pol == NULL)
        {
            printf("Failed memory allocation!\n");
            return -1;
        }

        pol->polynomial.coefficient = temp->polynomial.coefficient;
        pol->polynomial.exponent = temp->polynomial.exponent;

        temp = temp->next;
        pol->next = headRes->next;
        headRes = headRes->next;
    }

    return 0;
}

int multiplyPolynomials(struct Node *headPol1, struct Node *headPol2, struct Node *headRes)
{
    struct Node *i, *j, *pol, *temp;
    i = headPol1;

    while (i != NULL)
    {
        j = headPol2;
        while (j != NULL)
        {
            pol = (struct Node *)malloc(sizeof(struct Node));
            if (pol == NULL)
            {
                printf("Failed memory allocation!\n");
                return -1;
            }

            pol->polynomial.exponent = i->polynomial.exponent + j->polynomial.exponent;
            pol->polynomial.coefficient = i->polynomial.coefficient * j->polynomial.coefficient;
            temp = headRes;

            while (temp->next != NULL && temp->next->polynomial.exponent > pol->polynomial.exponent)
                temp = temp->next;

            if (temp->next != NULL && temp->next->polynomial.exponent == pol->polynomial.exponent)
            {
                temp->next->polynomial.coefficient += pol->polynomial.coefficient;
                free(pol);
            }
            else
            {
                pol->next = temp->next;
                temp->next = pol;
            }
            j = j->next;
        }
        i = i->next;
    }

    return 0;
}

int printList(struct Node *head)
{
    if (head == NULL)
        printf("The list is empty!\n");

    while (head != NULL)
    {
        printf("%d x^%d", head->polynomial.coefficient, head->polynomial.exponent);
        head = head->next;
        if (head != NULL)
            printf(" + ");
    }

    return 0;
}

int deleteList(struct Node *head)
{
    struct Node *temp;
    while (head->next != NULL)
    {
        temp = head->next;
        head->next = temp->next;
        free(temp);
    }

    return 0;
}

int main()
{
    struct Node *headPol1, *headPol2, *headSum, *headMult;
    headPol1->next = NULL;
    headPol2->next = NULL;
    headSum->next = NULL;
    headMult->next = NULL;

    return 0;
}
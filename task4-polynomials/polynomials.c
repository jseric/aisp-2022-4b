#include <stdio.h>
#include <stdlib.h>

typedef struct _Polynomial
{
    int coefficient;
    int exponent;
} Polynomial;

typedef struct _Node
{
    Polynomial polynomial;
    Polynomial *next;
} Node;

typedef enum
{
    false,
    true
} boolean;

// readPolynomial from file
// printPolynomial
// sumPolynomial
// addPolynomial

int readPolynomialFromFile(Node *head)
{
    char fileName[32];
    FILE *fPolynomialFile;
    Node *pol;
    Node *index;

    printf("File to read from: ");
    scanf("%s", fileName);

    fPolynomialFile = fopen(fileName, "r");

    if (fPolynomialFile == NULL)
    {
        printf("File empty!\n");
        return -1;
    }
    else
    {
        while (!feof(fPolynomialFile))
        {
            pol = (Polynomial *)malloc(sizeof(Node));
            scanf_s(fPolynomialFile, "%d %d", &pol->polynomial.coefficient, &pol->polynomial.exponent);

            if (pol->polynomial.coefficient == 0)
            {
                free(pol);
            }
            else
            {
                index = head->next;

                while (index->next != NULL && index->next->exponent > pol->polynomial.exponent)
                    index = index->next;

                if (index->next != NULL && index->next->exponent == pol->polynomial.exponent)
                {
                    index->next->exponent += pol->polynomial.coefficient;
                    free(pol);
                    if (index->next->coefficient == 0)
                    {
                        pol = index->next;
                        index->next = pol->next;
                        free(pol);
                    }
                }
                else
                {
                    pol->next = index->next;
                    index->next = pol;
                }
            }
        }
        fclose(fPolynomialFile);
    }

    return 0;
}

int printPolynomial(Node *head)
{
    boolean isFirstEl = true;

    while (head != NULL)
    {
        if (isFirstEl == true)
        {
            if (head->polynomial.coefficient == 1 && head->polynomial.exponent == 0)
                printf("1");
            if (head->polynomial.coefficient == -1 && head->polynomial.exponent == 0)
                printf("-1");
            if (head->polynomial.coefficient == 1 && head->polynomial.exponent > 0)
                printf("x^%d", head->polynomial.exponent);
            if (head->polynomial.coefficient == 1 && head->polynomial.exponent < 0)
                printf("x^%d", head->polynomial.exponent);
            if (head->polynomial.coefficient > 0 && head->polynomial.coefficient != 1 && head->polynomial.exponent > 0)
                printf("%d x^%d", head->polynomial.coefficient, head->polynomial.exponent);
            if (head->polynomial.coefficient < 0 && head->polynomial.coefficient != -1 && head->polynomial.exponent > 0)
                printf("-%d x%d", (-1) * head->polynomial.coefficient, head->polynomial.exponent);
            if (head->polynomial.coefficient > 0 && head->polynomial.coefficient != 1 && head->polynomial.exponent < 0)
                printf("%d x^%d", head->polynomial.coefficient, head->polynomial.exponent);
            if (head->polynomial.coefficient < 0 && head->polynomial.coefficient != -1 && head->polynomial.exponent < 0)
                printf("-%d x^%d", (-1) * head->polynomial.coefficient, head->polynomial.exponent);

            isFirstEl = false;
        }
        else
        {
            if (head->polynomial.coefficient == 1 && head->polynomial.exponent == 0)
                printf(" + 1");
            if (head->polynomial.coefficient == -1 && head->polynomial.exponent == 0)
                printf(" - 1");
            if (head->polynomial.coefficient == 1 && head->polynomial.exponent > 0)
                printf(" + x^%d", head->polynomial.exponent);
            if (head->polynomial.coefficient == 1 && head->polynomial.exponent < 0)
                printf(" + x^%d", head->polynomial.exponent);
            if (head->polynomial.coefficient > 0 && head->polynomial.exponent > 0)
                printf(" + %d x^%d", head->polynomial.coefficient, head->polynomial.exponent);
            if (head->polynomial.coefficient < 0 && head->polynomial.exponent > 0)
                printf(" - %d x^%d", (-1) * head->polynomial.coefficient, head->polynomial.exponent);
            if (head->polynomial.coefficient > 0 && head->polynomial.exponent < 0)
                printf(" + %d x^%d", head->polynomial.coefficient, head->polynomial.exponent);
            if (head->polynomial.coefficient < 0 && head->polynomial.exponent < 0)
                printf(" - %d x^%d", (-1) * head->polynomial.coefficient, head->polynomial.exponent);
        }

        head = head->next;
    }

    printf("\r\n");
}

int main()
{
    Node *head = NULL;
    head = (Node *)malloc(sizeof(Node));
    if (NULL == head)
    {
        printf("Initialisation failed!\n");
        return -1;
    }
    head->next = NULL;

    readPolynomialFromFile(head);
    printPolynomial(head);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct node *Position;
struct node
{
    int element;
    Position next;
};

int readFromFile(struct node *head)
{
    Position q = NULL;
    char fileName[32];

    printf("Input name of a file you want to read from: ");
    scanf("%s", fileName);

    FILE *fp = fopen(fileName, "r");

    if (NULL == fp)
    {
        printf("Failed to open the file!\n");
        return -1;
    }

    while (!feof(fp))
    {
        while (head->next != NULL)
        {
            head = head->next;
        }

        q = (Position *)malloc(sizeof(struct node));

        if (q == NULL)
        {
            printf("Allocation failed!\n");
            return -1;
        }

        fscanf(fp, "%d", &q->element);
        q->next = head->next;
        head->next = q;
    }
    fclose(fp);
    return 0;
}

int deleteList(struct node *head)
{
    Position temp;

    while (head->next != NULL)
    {
        temp = head->next;
        head->next = temp->next;
        free(temp);
    }

    return 0;
}

int printList(struct node *head)
{
    while (head != NULL)
    {
        printf("%d\n", head->element);
        head = head->next;
    }
    return 0;
}

int getUnion(struct node *head1, struct node *head2, struct node *headUnion)
{
    Position q = NULL;
    Position t = NULL;
    int temp = 0;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->element > head2->element)
        {
            temp = head2->element;
            head2 = head2->next;
        }
        else if (head1->element < head2->element)
        {
            temp = head1->element;
            head1 = head1->element;
        }
        else
        {
            temp = head1->element;
            head1 = head1->next;
            head2 = head2->next;
        }

        q = (Position *)malloc(sizeof(struct node));

        if (q == NULL)
        {
            printf("Allocation failed!\n");
            return -1;
        }

        q->element = temp;
        q->next = headUnion->next;
        headUnion->next = q;
        headUnion = q;
    }

    if (head1 == NULL)
    {
        t == head2;
    }
    else if (head2 == NULL)
    {
        t = head1;
    }

    while (t != NULL)
    {
        q = (Position *)malloc(sizeof(struct node));

        if (q == NULL)
        {
            printf("Allocation failed!\n");
            return -1;
        }

        q->element = t->element;
        q->next = headUnion->next;
        headUnion->next = q;
        headUnion = q;
        t = t->next;
    }
    return 0;
}

int getIntersection(struct node *head1, struct node *head2, struct node *headIntersection)
{
    Position q = NULL;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->element > head2->element)
        {
            head2 = head2->next;
        }
        else if (head1->element < head2->element)
        {
            head1 = head1->next;
        }
        else
        {
            q = (Position *)malloc(sizeof(struct node));

            if (q == NULL)
            {
                printf("Allocation has failed!\n");
                return -1;
            }

            q->element = head1->element;
            q->next = headIntersection->next;
            headIntersection->next = q;
            headIntersection = q;
            head1 = head1->next;
            head2 = head2->next;
        }
    }
    return 0;
}

int main()
{
    struct node head1, head2, headUnion, headIntersection;
    int readSuccess = 0;

    head1.next = NULL;
    head2.next = NULL;
    headUnion.next = NULL;
    headIntersection.next = NULL;

    printf("File for list1 L:\n");
    readSuccess = readFromFile(&head1);
    if (readSuccess < 0)
    {
        deleteList(&head1);
        return 0;
    }
    printList(&head1);

    printf("File for list2 U:\n");
    readSuccess = readFromFile(&head2);
    if (readSuccess < 0)
    {
        deleteList(&head2);
        deleteList(&head1);
        return 0;
    }
    printList(head2.next);

    printf("<<<----- Union ----->>>\n");
    readSuccess = getUnion(head1.next, head2.next, &headUnion);
    if (readSuccess < 0)
    {
        deleteList(&head1);
        deleteList(&head2);
        deleteList(&headUnion);
        return 0;
    }
    printList(headUnion.next);

    printf("<<<----- Internsection ----->>>\n");
    readSuccess = getIntersection(head1.next, head2.next, &headIntersection);
    if (readSuccess < 0)
    {
        deleteList(&head1);
        deleteList(&head2);
        deleteList(&headUnion);
        deleteList(&headIntersection);
        return 0;
    }

    printList(headIntersection.next);
    deleteList(&head1);
    deleteList(&head2);
    deleteList(&headUnion);
    deleteList(&headIntersection);
}
#include <stdio.h>
#include <stdlib.h>

typedef struct node *Position;
struct node
{
    int element;
    int priority;
    Position next;
};

int getRandomFromRange(int minVal, int maxVal)
{
    int value;
    return rand() % (maxVal + 1 - minVal) + minVal;
}

int pop(Position head)
{
    Position temp;
    temp = head;
    if (head->next != NULL)
    {
        temp = head->next;
        head->next = temp->next;
        free(temp);
    }
}

int push(Position head, int p)
{
    Position q = NULL;
    q = (Position *)malloc(sizeof(struct node));

    if (q == NULL)
    {
        printf("Allocation failed!\n");
        return -1;
    }

    q->element = p;
    q->priority = getRandomFromRange(1, 5);

    while (head->next != NULL && head->next->priority >= q->priority)
    {
        head = head->next;
    }
    q->next = head->next;
    head->next = q;
    return 0;
}

void deleteQueue(Position head)
{
    Position temp;
    while (head->next != NULL)
    {
        temp = head->next;
        head->next = temp->next;
        free(temp);
    }
}

void printQueue(Position head)
{
    printf("<<<---------- QUEUE ---------->>>\n");
    if (head == NULL)
    {
        printf("The queue is empty!\n");
    }
    else
    {
        while (head != NULL)
        {
            printf("%d\tPriority: %d\n", head->element, head->priority);
            head = head->next;
        }
    }
}

int main()
{
    struct node queueHead;
    queueHead.next = NULL;
    int inputCheck;

    int choice = 0;
    do
    {
        printf("<<<---------- MENU ---------->>>\n");
        printf("1 - Push\n2 - Pop\n3 - Print queue\n0 - Close\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            inputCheck = push(&queueHead, getRandomFromRange(1, 5));
            if (inputCheck < 0)
            {
                deleteQueue(&queueHead);
                return 0;
            }
            break;

        case 2:
            pop(&queueHead);
            break;

        case 3:
            printQueue(&queueHead);
            break;

        case 0:
            deleteQueue(&queueHead);
            break;

        default:
            break;
        }

    } while (choice != 0);
}
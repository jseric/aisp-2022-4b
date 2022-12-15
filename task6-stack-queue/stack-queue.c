#include <stdio.h>
#include "stack-queue-methods.h"

int main(){

    int choice = 0;
    int input;

    struct Node *stackHead = (struct Node *)malloc(sizeof(struct Node));
    if (NULL == stackHead)
    {
        printf("Initialisation failed!\n");
        return -1;
    }
    stackHead->next = NULL;

    struct Node *queueHead = (struct Node *)malloc(sizeof(struct Node));
    if (NULL == queueHead)
    {
        printf("Initialisation failed!\n");
        return -1;
    }
    queueHead->next = NULL;

     do
    {
        printf("<<<<<< MENU >>>>>>\n");
        printf("\t0 - end\n");
        printf("\t1 - push to stack\n");
        printf("\t2 - pop from stack\n");
        printf("\t3 - print stack contents\n");
        printf("\t4 - add to queue\n");
        printf("\t5 - remove from queue\n");
        printf("\t6 - print queue contents\n");

        scanf(" %d", &choice);

        switch (choice)
        {
        case 0:
            break;
        
        case 1:
        {
            printf("Value to push:\t");
            scanf(" %d", &input);
            if (stackPush(input, &stackHead) == -1){
                printf("Error!\n");
                clearList(&stackHead);
                return 0;
            }
            break;
        }
        case 2:
        {
            printf("Popped value:\t%d", stackPop(stackHead->next));
            break;
        }
        case 3:
        {
            printList(stackHead->next);
            break;
        }
        case 4:
        {
            printf("Value to queue:\t");
            scanf(" %d", &input);
            if (addToQ(input, queueHead) == -1){
                printf("Error!\n");
                clearList(&queueHead);
                return 0;
            }
            break;
        }
        case 5:
        {
            printf("Removed value:\t%d", removeFromQ(queueHead->next));
            break;
        }
        case 6:
        {
            printList(queueHead->next);
            break;
        }
        default:
            break;
        }

    }while (choice != 0);

    return 1;
}
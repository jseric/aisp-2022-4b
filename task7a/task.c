#include "methods.h"

int main(){

    int limit, select, input, c = 0;
 
    struct Node *stackHead = (struct Node *)malloc(sizeof(struct Node));
    if (NULL == stackHead)
    {
        printf("Initialisation failed!\n");
        return -1;
    }
    stackHead->next = NULL;

    printf("Stack limit:\t");
    scanf(" %d", &limit);

    do
    {
        printf("<<<<<< MENU >>>>>>\n");
        printf("\t0 - end\n");
        printf("\t1 - push to stack\n");
        printf("\t2 - pop from stack\n");
        printf("\t3 - stack contents\n");

        scanf(" %d", &select);

        switch (select)
        {
        case 0:
        {
            clearList(stackHead);
            break;
        }
        case 1:
        {
            printf("Enter value to push:\t");
            scanf(" %d", &input);
            if(pushToStack(input, &c, limit, &stackHead) == -1){
                printf("Error!\n");
                clearList(stackHead);
                break;
            }
            break;
        }
        case 2:
        {
            printf("Popped value:\t%d", popFromStack(&c, stackHead->next));
            break;
        }
        case 3:
        {
            printList(stackHead->next);
            break;
        }
        
        default:
            break;
        }
    } while (select != 0);
    

    return 1;
}
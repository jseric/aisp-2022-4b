#include "stack-queue-structs.h"
#include <stdlib.h>

int stackPush(int value, struct Node** s){
    
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (NULL == newNode)
    {
        printf("Memory allocation failed!\n");
        return -1;
    }
    
    newNode->val = value;

    (*newNode).next = (*s)->next;
    (*s)->next = newNode;

    return 1;

}

int stackPop(struct Node *top){

    if(NULL == top){
        printf("Stack empty!\n");
        return -1;
    }
    
    struct Node *tmp = top;
    int tmpVal = top->val;

    top = top->next;
    free(tmp);

    return tmpVal;

}

void printStackContents(struct Node *top){
    
    if (NULL == top)
    {
        printf("List empty!\n");
        return;
    }

    
    while (top != NULL)
    {
        printf("value: %d\n", top->val);
        top = top->next;
    }

}

int clearList(struct Node *head){

    struct Node *tmp = head;
    while(NULL != head->next){
        head = head->next;
        free(tmp);
        tmp = head;
    }
    printf("List cleared.\n");

    return 1;

}
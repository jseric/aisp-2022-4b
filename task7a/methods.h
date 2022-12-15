#include "structs.h"
#include <stdio.h>
#include <stdlib.h>

int pushToStack(int value, int *c, int limit, struct Node **s){

    if ((*c) < limit)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        if (NULL == newNode)
        {
            printf("Memory allocation failed!\n");
            return -1;
        }
        
        (*c)++;
        newNode->val = value;

        (*newNode).next = (*s)->next;
        (*s)->next = newNode;

        return 1;
    }

    printf("Stack full!\nPlease pop a value before pushing.\n");

    return -2;
}


int popFromStack(int *c, struct Node *top){

    if(NULL == top){
        printf("none! Stack empty!\n");
        return -1;
    }
    
    struct Node *tmp = top;
    int tmpVal = top->val;

    top = top->next;
    free(tmp);

    (*c)--;

    return tmpVal;

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

void printList(struct Node *top){
    
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
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "postfix-structs.h"

int stackPush(int value, struct Node** s){
    
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (NULL == newNode)
    {
        printf("PUSH Memory allocation failed!\n");
        return -1;
    }
    
    (*newNode).data = value;

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
    int tmpVal = top->data;

    top = top->next;
    free(tmp);

    return tmpVal;

}

void readPostfixLine(char exp[256]){

    FILE *fp = fopen("postfix.txt", "r+");
    if (NULL == fp)
    {
        printf("Failed to read file!\n");
        return;
    }

    if(fgets(exp, 255, fp) == NULL){
        printf("No expression to read!\n");
    }

    return;
}

int evaluateExp(struct Node *top, char exp[256]){

    int i = 0;

    for(i = 0; exp[i]; ++i){

        if(exp[i] == ' ') continue;

        else if(isdigit(exp[i])){
            int num = 0;
            while (isdigit(exp[i]))
            {
                num = 10 * num + (int)(exp[i]-'0');
                ++i;
            }
            --i;

            stackPush(num, &top);
            
        }

        else {
            int second = stackPop(top);
            int first = stackPop(top);
            switch (exp[i])
            {
            case '+':
                stackPush(first + second, &top);
                break;
            case '-':
                stackPush(first - second, &top);
                break;
            case '/':
                stackPush(first / second, &top);
                break;
            case '*':
                stackPush(first * second, &top);
                break;            
            default:
                break;
            }
        }

    }

    return stackPop(top);
}

void printList(struct Node *top){
    
    if (NULL == top)
    {
        printf("List empty!\n");
        return;
    }

    
    while (top != NULL)
    {
        printf("value: %d\n", top->data);
        top = top->next;
    }

}
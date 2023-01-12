#include <stdio.h>
#include <stdlib.h>
#include "postfix-methods.h"

int main(){

    char expression[256] = "";
    int result = 0;

    struct Node *top = (struct Node *)malloc(sizeof(struct Node));
    if (NULL == top)
    {
        printf("Initialisation failed!\n");
        return -1;
    }
    top->next = NULL;

    readPostfixLine(expression);
    if(strcmpi(expression, "") == 0){
        return -1;
    }

    result = evaluateExp(top, expression);

    printf("\n\nexpression: %s", expression);
    printf("\n\n result: %d\n", result);

    return 1;

}
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "studentStruct.h"

int studentCount(){

    int n = 0;
    char str[128];
    FILE *fp = NULL;

    fp = fopen("students.txt", "r");
    if (NULL == fp)
    {
        printf("File open failed!\n");
        return -1;
    }

    while (!feof(fp))
    {
        fgets(str, 128, fp);
        ++n;
    }

    fclose(fp);
    return n;
}

int fillArray(Student arr[]){
    
    char str[128];
    int counter = 0;
    FILE *fp = NULL;

    fp = fopen("students.txt", "r");
    if (NULL == fp)
    {
        printf("File empty!\n");
        return -1;
    }

    while (!feof(fp))
    {
        arr[counter].relativePoints = 0;

        fgets(str, 127, fp);
        sscanf(str, " %s %s %d", arr[counter].name, arr[counter].surname, &arr[counter].absolutePoints);
        ++counter;
    }

    fclose(fp);
    return 1;
}

int findMaxPoints(Student arr[], int len){

    int max = arr[0].absolutePoints;

    for(int c = 1; c < len; c++){
        if (arr[c].absolutePoints > max)
        {
            max = arr[c].absolutePoints;
        }
    }

    return max;
}

int calcRelativePoints(Student arr[], int len, int maxPoints){

    for (int i = 0; i < len; i++)
    {
        arr[i].relativePoints = (float)arr[i].absolutePoints / (float)maxPoints * 100;
    }

    return 1;
}

int printResults(Student arr[], int len){

    for(int i = 0; i < len; i++){

        printf("%s %s %d %f\n", arr[i].name, arr[i].surname, arr[i].absolutePoints, arr[i].relativePoints);

    }


    return 1;
}
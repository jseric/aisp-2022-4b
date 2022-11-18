#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "studentMethods.h"

int main()
{
    Student *students;
    int numberOfStudents = 0;
    char str[128] = "";
    int i = 0;
    int maxPoints = 0;

    numberOfStudents = studentCount();

    students = (Student *)malloc(numberOfStudents * sizeof(Student));
    if (NULL == students){
        printf("Dynamic allocation failed.\n");
        return -1;
    }

    fillArray(students);
    maxPoints = findMaxPoints(students, numberOfStudents);
    calcRelativePoints(students, numberOfStudents, maxPoints);

    printResults(students, numberOfStudents);
    
    free(students);
    return 0;
}
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

typedef struct
{
    char name[32];
    char surname[32];
    int absolutePoints;
    float relativePoints;
} Student;

int studentCount(FILE *fp, int *n, char str[]){

    while (!feof(fp))
    {
        fgets(str, 128, fp);
        (*n)++;
    }

    return 1;
}

int fillArray(Student arr[], FILE *fp, char str[]){
    
    int counter = 0;

    while (!feof(fp))
    {
        arr[counter].relativePoints = 0;

        fgets(str, 127, fp);
        sscanf(str, "%s %s %d", arr[counter].name, arr[counter].surname, &arr[counter].absolutePoints);
        counter++;
    }

    return 1;
}

int findMaxPoints(Student arr[], int len, int *max){

    for(int c = 0; c < len; c++){
        if (arr[c].absolutePoints > (*max))
        {
            (*max) = arr[c].absolutePoints;
        }
    }

    return 1;
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

int main()
{
    Student *students;
    int numberOfStudents = 0;
    char str[128] = "";
    int i = 0;
    int maxPoints = 0;

    FILE *fStudentResults = NULL;
    fStudentResults = fopen("students.txt", "r");

    if (fStudentResults == NULL)
    {
        printf("File empty!\n");
        return -1;
    }

    studentCount(fStudentResults, &numberOfStudents, str);

    students = (Student *)malloc(numberOfStudents * sizeof(Student));
    rewind(fStudentResults);

    fillArray(students, fStudentResults, str);
    findMaxPoints(students, numberOfStudents, &maxPoints);
    calcRelativePoints(students, numberOfStudents, maxPoints);

    printResults(students, numberOfStudents);
    

    fclose(fStudentResults);
    free(students);
    return 0;
}
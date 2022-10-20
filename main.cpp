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

int main()
{
    Student *students;
    int numberOfStudents = 0;
    char str[128] = "";

    FILE *fStudentResults = NULL;
    fStudentResults = fopen("students.txt", "r");

    if (fStudentResults == NULL)
    {
        printf("File empty!\n");
        return -1;
    }

    while (!feof(fStudentResults))
    {
        fgets(str, 128, fStudentResults);
        numberOfStudents++;
    }

    students = (Student *)malloc(numberOfStudents * sizeof(Student));
    rewind(fStudentResults);

    int i = 0;
    int maxPoints = 0;
    while (!feof(fStudentResults))
    {
        students[i].relativePoints = 0;

        fgets(str, 127, fStudentResults);
        sscanf(str, "%s %s %d", students[i].name, students[i].surname, &students[i].absolutePoints);

        if (students[i].absolutePoints > maxPoints)
        {
            maxPoints = students[i].absolutePoints;
        }
        i++;
    }

    for (int i = 0; i < numberOfStudents; i++)
    {
        students[i].relativePoints = (float)students[i].absolutePoints / (float)maxPoints * 100;

        printf("%s %s %d %f\n", students[i].name, students[i].surname, students[i].absolutePoints, students[i].relativePoints);
    }

    fclose(fStudentResults);
    free(students);
    return 0;
}
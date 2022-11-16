typedef struct _Person
{
    char name[32];
    char lastname[32];
    int yearOfBirth;
} Person;

struct Node
{
    Person data;
    struct Node * next;
};

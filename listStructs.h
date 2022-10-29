typedef struct _Person
{
    char name[32];
    char lastname[32];
    int yearOfBirth;
} Person;

typedef struct _Node
{
    Person data;
    struct _Node * next;
} Node;

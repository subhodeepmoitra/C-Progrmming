#include<stdio.h>

struct Person{
    char name[100];
    int age;
};

int main(){
    int no_of_people;
    printf("Enter the no of people: ");
    scanf("%d", &no_of_people);

    struct Person people_array[no_of_people];

    for (int i = 0; i < no_of_people; i++)
    {
        printf("Name: ");
        scanf("%s", people_array[i].name); //since by %s we are using pointers so & not needed for string input
        printf("Age: ");
        scanf("%d", &people_array[i].age);
    }

    printf("Eligible Voters: \n");
    for (int i = 0; i < no_of_people; i++)
    {
        printf("%s -> ", people_array[i].name);
        if (people_array[i].age >= 18)
        {
            printf("Eligible \n");
        } else {
            printf("Not Eligible \n");
        }
        
    }
    return 0;
    
}
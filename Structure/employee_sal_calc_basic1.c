#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Employee{
    int id;
    char name[100];
    float basic;
    float da;
    float hra;
    float gross;
};

int main() {
    int number_employees;

    printf("Enter the number of employees: ");
    scanf("%d", &number_employees);

    struct Employee emp[number_employees];

    for (int i = 0; i < number_employees; i++) {
        printf("\nEnter details for employee %d:\n", i + 1);
        printf("Service Number: ");
        scanf("%d", &emp[i].id);
        printf("Name (start with rank): ");
        scanf("%s", emp[i].name);
        printf("Basic: ");
        scanf("%f", &emp[i].basic);

        emp[i].da = 0.80 * emp[i].basic;
        emp[i].hra = 0.15 * emp[i].basic;
        emp[i].gross = emp[i].basic + emp[i].da + emp[i].hra;
    }

    printf("ID          Name                Basic           DA           HRA           Gross\n");
    for (int i = 0; i < number_employees; i++){
        printf("%-10d  %-18s  %-12.2f  %-11.2f  %-11.2f  %-12.2f\n",
               emp[i].id, emp[i].name, emp[i].basic, emp[i].da, emp[i].hra, emp[i].gross);
    }
    
    return 0;
}

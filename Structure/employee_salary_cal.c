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

void calculateSalary(struct Employee *emp){
    emp->da = 0.80*emp->basic;
    emp->hra = 0.15*emp->basic;
    emp->gross = emp->da + emp->hra;
}

int main(){
    int number_employees;
    printf("Enter the number of employees: ");
    scanf("%d",&number_employees);

    struct Employee *emp;
    emp = (struct Employee *)malloc(number_employees*sizeof(struct Employee));

    if (emp == NULL)
    {
        printf("Memory allocation failed...");
        return -1;
    }

    for (int i = 0; i < number_employees; i++)
    {
        printf("Enter detail for employee %d:\n", i+1);
        printf("Service Number: ");
        scanf("%d",&emp[i].id);
        printf("Name (start with rank): ");
        scanf("%s",emp[i].name);
        printf("Basic: ");
        scanf("%f",&emp[i].basic);
        calculateSalary(&emp[i]);
    }

    printf("\n----------------------Employee Details-------------------------\n");
    printf("ID        Name                   Basic           DA           HRA         Gross\n");
    for (int i = 0; i < number_employees; i++)
    {
        printf("%5d   %18s   %12.2f   %9.2f   %9.2f   %12.2f\n",
        emp[i].id, emp[i].name, emp[i].basic, emp[i].da, emp[i].hra, emp[i].gross);
    }
    free(emp);
    return 0;       
    
}
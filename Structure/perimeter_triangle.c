//Finding the least cost airline model
#include<stdio.h>
#include<string.h>

struct Model{
    char name[50];
    float distance;
    float fuel;
    float cost;
};

int main(){
    int n;
    printf("Enter number of aircraft models in current fleet: ");
    scanf("%d",&n);
    float fuel_price;
    printf("Enter the fuel price per liter: ");
    scanf("%f",&fuel_price);
    struct Model model[n];
    printf("Enter the details: \n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter details of aircraft %d\n",i+1);
        printf("Model name: ");
        scanf("%s",model[i].name);
        printf("Max distance: ");
        scanf("%f",&model[i].distance);
        printf("Fuel Capacity: ");
        scanf("%f",&model[i].fuel);
        model[i].cost = model[i].distance * model[i].fuel * fuel_price;
    }
    printf("The entered details are as follows: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d %-5s %-3f %-3f %-3f\n", i+1, model[i].name, model[i].distance, model[i].fuel, model[i].cost);
    }
    float least_cost = model[0].cost;
    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        if (model[i].cost < least_cost)
        {
            least_cost = model[i].cost;
            counter = i;
        }
    }
    printf("%s is the efficient for having the least cost of %2.2f\n",model[counter].name, least_cost);
    return 0;
}
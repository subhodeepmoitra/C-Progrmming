#include<stdio.h>
#include<string.h>

struct Candidate{
    char name[50];
    int maths;
    int physics;
    int total;
};

int main(){
    int n;
    printf("Enter number of candidates: ");
    scanf("%d", &n);
    struct Candidate candidate[n];
    printf("Enter the datails of the candidates: \n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter details of Candidate %d\n",i+1);
        printf("Name: ");
        scanf("%s",candidate[i].name);
        printf("Maths: ");
        scanf("%d",&candidate[i].maths);
        printf("Physics: ");
        scanf("%d",&candidate[i].physics);
        candidate[i].total = candidate[i].maths + candidate[i].physics;
    }
    for (int i = 0; i < n; i++)
    {
        printf("ID: %d Name: %s Maths: %d Physics: %d Total: %d\n",
                i+1, candidate[i].name, candidate[i].maths, candidate[i].physics, candidate[i].total);
    }
    int max = candidate[0].total;
    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        if (candidate[i].total > max)
        {
            max = candidate[i].total;
            counter = i;
        }
    }
    printf("%s got the highest by scoring %d\n",candidate[counter].name, max);
    return 0;   
    
}
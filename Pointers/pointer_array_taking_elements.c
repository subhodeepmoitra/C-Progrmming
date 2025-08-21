#include<stdio.h>
#include<stdlib.h>

int linearSearch(int *arr, int upper_bound, int element){
    for (int i = 0; i < upper_bound; i++)
    {
        if (*(arr+i) == element)
        {
            return i;
        }
        
    }
    return -1;
}

int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n*sizeof(int));

    for (int i = 0; i < n; i++)
    {
        printf("Enter element at pos %d -> ", i);
        scanf("%d",(arr+i));
    }

    int element;
    char choice;
    do
    {
        printf("Enter the element to be searched: ");
        scanf("%d", &element);
        int searchStatus = linearSearch(arr, n, element);
        if (searchStatus != -1)
        {
            printf("Success at %d\n", searchStatus);
        } else {
            printf("Search Failed\n");
        }
        printf("Do you want to continue searching (y): ");
        scanf(" %c", &choice); //here the space before %c is very important otherwise the program terminates because it marks end
        } while (choice == 'y');
    
    free(arr);
    return 0;    
}
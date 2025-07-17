#include<stdio.h>

int main(){
    int seen[10] = {0};
    long long number;
    printf("Enter a number: ");
    scanf("%lld",&number);

    int remainder;
    while (number > 0)
    {
        /* code */
        remainder = number % 10;
        if (seen[remainder] == 1)
        {
            break;
        }
        seen[remainder]=1;
        number=number/10;
    }
    if (number > 0)
    { printf("Yes");} else {printf("No");}
    printf("\n");
    return 0;
}
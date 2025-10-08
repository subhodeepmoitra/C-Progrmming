#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

typedef struct polynomial {
    int coff;
    int power;
    struct polynomial *next;
} Poly;

void insertEnd(Poly **ptr, int c, int p){
    Poly *new_node, *cur;
    new_node = (Poly *)malloc(sizeof(Poly));
    new_node -> coff = c;
    new_node -> power = p;
    new_node -> next = NULL;
    if (*ptr == NULL)
    {
        *ptr = new_node;
    } else {
        cur = *ptr;
        while (cur -> next != NULL)
        {
            cur = cur -> next;
        }
        cur -> next = new_node;
    }
}

void createPoly(Poly **p){
    int cof, pr;
    char ch;
    while (1)
    {
        printf("Enter coefficient: ");
        scanf("%d", &cof);
        printf("Enter power: ");
        scanf("%d", &pr);
        insertEnd(p, cof, pr);
        printf("Continue (y/n): ");
        //fflush(stdin);
        scanf(" %c", &ch);
        if (toupper(ch) == 'N')
        {
            break;
        }
    }
}

void display(Poly *ptr){
    while (ptr != NULL)
    {
        printf("%dx^%d+", ptr->coff,ptr->power);
        ptr=ptr->next;
    }
    printf("\b ");
}

void addPoly(Poly *h1, Poly *h2, Poly **h3){
    while (h1 && h2)
    {
        if (h1->power > h2->power)
        {
            insertEnd(h3, h1->coff, h1->power);
            h1=h1->next;
        }
        else {
            if (h1->power < h2->power)
            {
                insertEnd(h3, h2->coff, h2->power);
                h2=h2->next;
            }
            else {
                insertEnd(h3, h1->coff + h2->coff, h1->power);
                h1 = h1->next;
                h2 = h2->next;
            }
        }
    }
        while (h1)
        {
            insertEnd(h3, h1->coff, h1->power);
            h1=h1->next;
        }
        while (h2)
        {
            insertEnd(h3, h2->coff, h2->power);
            h2=h2->next;
        }
    }

int main(){
    Poly *head1 = NULL, *head2 = NULL, *head3 = NULL;
    printf("Enter value for first polynomial: \n");
    createPoly(&head1);
    printf("Enter value for second polynomial: \n");
    createPoly(&head2);
    addPoly(head1, head2, &head3);
    printf("\n First Polynomial: ");
    display(head1);
    printf("\n Second Polynomial: ");
    display(head2);
    printf("\n Resultant Polynomial: ");
    display(head3);
    return 0;
}
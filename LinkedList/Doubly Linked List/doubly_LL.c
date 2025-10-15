#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    struct node *prev;
    int data;
    struct node *next;
} DNode;

void insertBeginning(DNode **p, int n) {
    DNode *q = (DNode *)malloc(sizeof(DNode));
    q->data=n;
    q->prev=NULL;
    q->next=*p;
    if (*p!=NULL)
    {
        (*p)->prev=q;
    }
    *p=q;
}

void insertAtPosition(DNode **p, int n, int pos) {
    DNode *q, *r;
    int i;
    q = (DNode *)malloc(sizeof(DNode));
    q->data=n;
    if (*p==NULL || pos==1)
    {
        q->prev=NULL;
        q->next=*p;
        if (*p!=NULL)
        {
            (*p)->prev=q;
        }
        *p=q;
    }
    else {
        r=*p;
        for(i=1; i<=pos-2&&r->next!=NULL; i++) {
            r=r->next;
        }
        q->prev=r;
        q->next=r->next;
        if (r->next != NULL)
        {
            r->next->prev=q;
        }
        r->next=q;
    }
}

void reverseDisplay(DNode *p) {
    if (p==NULL)
    {
        printf("Empty Linked List");
    }
    else {
        while (p->next != NULL)
        {
            p=p->next;
        }
        while (p!=NULL)
        {
            printf("%d ", p->data);
            p = p->prev;
        }
        
    }
}

int main(){
    DNode *head = NULL;
    int choice, value, pos;

    while (1) {
        printf("\n1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete at Beginning\n");
        printf("4. Delete at End\n");
        printf("5. Reverse display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertBeginning(&head, value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAtPosition(&head, value, pos);
                break;
            case 3:
                //deleteAtBeginning(&head);
                break;
            case 4:
               // deleteAtEnd(&head);
                break;
            case 5:
                reverseDisplay(head);
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

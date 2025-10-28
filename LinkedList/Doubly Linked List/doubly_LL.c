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

void insertEnd(DNode **p, int n) {
    DNode *q, *r;
    q = (DNode *)malloc(sizeof(DNode));
    q->data = n;
    q->next = NULL;

    if (*p == NULL) {
        q->prev = NULL;
        *p = q;
    } else {
        r = *p;
        while (r->next != NULL) {
            r = r->next;
        }
        r->next = q;
        q->prev = r;
    }
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

void deleteFirst(DNode **p) {
    DNode *r = *p;
    if (*p == NULL)
    {
        printf("Empty Linked List");
    }
    else {
        if (r->next!=NULL)
        {
            r->next->prev=NULL;
        }
        *p = r->next;
        free(r);
    }
}

void deleteLast(DNode **p) {
    DNode *r = *p;
    if (*p == NULL) {
        printf("Empty Linked List");
    } else if (r->next == NULL) {
        free(r);
        *p = NULL;
    } else {
        while (r->next != NULL) {
            r = r->next;
        }
        r->prev->next = NULL;
        free(r);
    }
}

void deleteAtPosition(DNode **p, int pos) {
    DNode *r=*p, *temp;
    int i;
    if (*p==NULL)
    {
        printf("Empty Linked List");
    }
    else {
        if (pos == 1)
        {
            if (r->next!=NULL)
            {
                r->next->prev=NULL;
            }
            *p=r->next;
            free(r);
        }
        else {
            for(i=1; i<=pos-2&&r->next!=NULL; i++) {
                r=r->next;
            }
            if (r->next==NULL)
            {
                printf("Invalid Position");
            }
            else {
                temp=r->next;
                r->next=temp->next;
                if (temp->next!=NULL)
                {
                    temp->next->prev=r;
                }
                free(temp);
            }
        }
    }
}

void display(DNode *p) {
    if (p == NULL) {
        printf("Empty Linked List");
    } else {
        while (p != NULL) {
            printf("%d ", p->data);
            p = p->next;
        }
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
        printf("2. Insert at Position\n");
        printf("3. Insert at End\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at Position\n");
        printf("6. Delete at End\n");
        printf("7. Reverse display List\n");
        printf("8. Normal order display\n");
        printf("9. Exit\n");
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
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(&head, value);
                break;
            case 4:
                deleteFirst(&head);
                break;
            case 5:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAtPosition(&head, pos);
                break;
            case 6:
                deleteLast(&head);
                break;
            case 7:
                reverseDisplay(head);
                break;
            case 8:
                display(head);
                break;
            case 9:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void insertAtBeginning(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node)); 
    newNode->data = value;
    if (*head == NULL) {
        newNode->next = newNode;  // first node pointing to self
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }

    newNode->next = *head; 
    temp->next = newNode; 
    *head = newNode;  
}

void insertAtEnd(Node **p, int n) {
    Node *q, *r=*p;
    q=(Node *)malloc(sizeof(Node));
    q->data=n;
    if (*p==NULL)
    {
        q->next=q;
        *p=q;
    }
    else {
        q->next=*p;
        while (r->next!=*p)
        {
            r=r->next;
        }
        r->next=q;
    }
}

void insertAtPosition(Node **p, int n, int pos) {
    Node *q, *r=*p;
    int i;
    q=(Node *)malloc(sizeof(Node));
    q->data=n;
    if (*p==NULL)
    {
        q->next=*p;
        *p=q;
    }
    else {
        if (pos==1)
        {
            q->next=*p;
            while (r->next!=*p)
            {
                r=r->next;
            }
            r->next=q;
            *p=q;
        }
        else {
            for (i = 1; i <= pos-2&&r->next!=*p; i++)
            {
                r=r->next;
            }
            q->next = r->next;
            r->next = q;
        }
    }
}

void deleteAtBeginning(Node **p) {
    Node *r=*p;
    if (*p==NULL)
    {
        printf("Empty LL");
    }
    else {
        if (r->next==*p)
        {
           free(*p);
           *p=NULL;
        }
        else {
            while (r->next!=*p)
            {
                r=r->next;
            }
            r->next=(*p)->next;
            free(*p);
            *p=r->next;
        }
    }
}

void deleteAtEnd(Node **p) {
    Node *r = *p;
    if (*p==NULL)
    {
        printf("Empty LL");
    }
    else {
        if (r->next==*p)
        {
            free(*p);
            *p=NULL;
        }
        else {
            while (r->next->next!=*p)
            {
                r=r->next;
            }
            free(r->next);
            r->next=*p;
        }
    }
}

void deleteAtPosition(Node **p, int pos) {
    Node *r=*p, *temp;
    int i;
    if (*p==NULL)
    {
        printf("Empty LL");
    }
    else {
        if (pos == 1)
        {
            if (r->next==*p)
            {
                free(*p);
                *p=NULL;
            }
            else {
                while (r->next!=*p)
                {
                    r=r->next;
                }
                r->next=(*p)->next;
                free(*p);
                *p=r->next;
            }
        }
        else {
            for (i = 1; i <= pos-2 && r->next!=*p; i++)
            {
                r=r->next;
            }
            if (r->next==*p)
            {
                printf("Invalid Position");
            }
            
            else {
                temp=r->next;
                r->next=temp->next;
                free(temp);
            }
        }
    }
}

void displayList(Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("Circular Linked List: ");
    Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);  // stop when go to the head from end node
    printf("(back to head)\n");
}


int main() {
    Node* head = NULL;
    int choice, value, pos;

    while (1) {
        printf("\n1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Specific Position\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Specific Position\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAtPosition(&head, value, pos);
                break;
            case 4:
                deleteAtBeginning(&head);
                break;
            case 5:
                deleteAtEnd(&head);
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAtPosition(&head, pos);
                break;
            case 7:
                displayList(head);
                break;
            case 8:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

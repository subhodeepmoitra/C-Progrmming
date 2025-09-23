#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Insert at the beginning
void insertAtBeginning(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node)); //creating a new node and dynamically allocates memory
    newNode->data = value; //init the data
    newNode->next = *head; //link the new node to the current first node (head)
    *head = newNode; //moving the head so it now points to the new node (now node becomes the first node)
    printf("Inserted %d at the beginning.\n", value);
}

// Insert at the end
void insertAtEnd(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node)); //creating a new node
    newNode->data = value; //init the data in the new node
    newNode->next = NULL; //as inserting at end so point the next to NULL

    if (*head == NULL) { //checks if the list is empty
        *head = newNode; //makes the new first node
        printf("Inserted %d at the end.\n", value);
        return;
    }

    Node* temp = *head; //the temp is a traversal pointer and initially points to the first node (*head)
    while (temp->next != NULL) { //traverses through the list till the last node(whose next is NULL)
        temp = temp->next; //if not null then move to the next node
    }
    temp->next = newNode; //here now temp is the last node so we make its next pointer point to the new node
    printf("Inserted %d at the end.\n", value);
}

// Insert at specific position
void insertAtPosition(Node** head, int value, int pos) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (pos == 1) { //when the pos is 1 then insertion at beginning
        newNode->next = *head;
        *head = newNode;
        printf("Inserted %d at position %d.\n", value, pos);
        return;
    }

    Node* temp = *head; //we create a temp pointer that points to the first node (*head)
    //we do this because we don't move the actual *head so we don't loose the track of the starting point of the list
    for (int i = 1; temp != NULL && i < pos - 1; i++) { //we traverse till the previous node of the required position node
        temp = temp->next; //move to the next node
    }

    if (temp == NULL) { //if the temp is NULL then we have reqched out of the boundary of the list
        printf("Position out of range!\n");
        free(newNode); //so for this we free the memory
        return;
    }

    newNode->next = temp->next; //temp->next currently points to the node that used to be at pos.
    // So we set newNode->next to point to that node — so we don’t lose the rest of the list.
    temp->next = newNode; //Now we make the previous node (temp) point to our new node.
    printf("Inserted %d at position %d.\n", value, pos);
}

void insertAtPositionNew(Node** head, int value, int pos){
    Node* newNode = (Node *)malloc(sizeof(Node));
    Node* r;
    int i;
    newNode -> data = value;
    if (*head == NULL || pos == 1)
    {
        newNode -> next = *head;
        *head = newNode;
    } else {
        r = *head;
        for (i = 1; i <= pos-2 && r->next != NULL; i++)
        {
            r = r->next;
        }
    newNode->next = r->next;
    r->next = newNode;
        
    }
    
}

// Delete at beginning
void deleteAtBeginning(Node** head) {
    if (*head == NULL) { //when the list is empty
        printf("List is empty!\n");
        return;
    }
    Node* temp = *head; //*temp stores the current first node
    *head = (*head)->next; //moves the head forward to the next node so now *head->next is the second node or NULL if only 1 node
    printf("Deleted %d from the beginning.\n", temp->data);
    free(temp); //free the memory of temp
}

// Delete at end
void deleteAtEnd(Node** head) {
    if (*head == NULL) { //if list empty
        printf("List is empty!\n");
        return;
    }
    Node* temp = *head; //*temp stores the current first node
    if (temp->next == NULL) { //when the next points to NULL then we are at the last node
        printf("Deleted %d from the end.\n", temp->data);
        free(temp); //free the memory of temp
        *head = NULL; //and then make *head NULL
        return;
    }
    while (temp->next->next != NULL) { //when next doesn't point to NULL then it is not tha last node
        temp = temp->next; //move to the next node
    }
    printf("Deleted %d from the end.\n", temp->next->data);
    free(temp->next); //frees the memory from the last node
    temp->next = NULL; //it makes the second last node point to NULL so it becomes the current last node
}

// Delete at specific position
void deleteAtPosition(Node** head, int pos) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node* temp = *head;

    if (pos == 1) {
        *head = (*head)->next;
        printf("Deleted %d from position %d.\n", temp->data, pos);
        free(temp);
        return;
    }

    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range!\n");
        return;
    }

    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    printf("Deleted %d from position %d.\n", nodeToDelete->data, pos);
    free(nodeToDelete);
}

void deleteAtPosition1(Node** head, int pos){
    Node* temp = *head;
    Node *t;
    int i;
    if (*head == NULL)
    {
        printf("Empty List");
    } else {
        if (pos == 1)
        {
            *head = temp->next;
            free(temp);
        } else {
            for (i=1; i<=pos-2&&temp->next!=NULL; i++)
            {
                temp = temp->next;
            }
            if (temp -> next == NULL)
            {
                printf("Invalid Position");
            } else {
                t = temp->next;
                temp->next = t->next;
                free(t);
            }
        }
        
    }
    
}

// Display linked list
void displayList(Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    printf("Linked List: ");
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
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
                //insertAtPosition(&head, value, pos);
                insertAtPositionNew(&head, value, pos);
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
                //deleteAtPosition(&head, pos);
                deleteAtPosition1(&head, pos);
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

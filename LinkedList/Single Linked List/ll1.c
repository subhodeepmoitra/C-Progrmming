#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;  // Global head pointer

struct Node* createNode(int value) {
    //func. to create a node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); //dynamically allocate memory for a node
    newNode->data = value; //init the data
    newNode->next = NULL; //set the next to NULL so it don't point anything
    return newNode; //return the address of the new node so we can link it later
}

// Insert at the beginning
void insertAtBeginning(int value) {
    struct Node* newNode = createNode(value); //create a new node
    newNode->next = head; //the next of the node points to the current head
    head = newNode; //moving the head to point to this new node
    printf("Inserted %d at the beginning.\n", value);
}

// Insert at end
void insertAtEnd(int value) {
    struct Node* newNode = createNode(value); //creating a new node
    if (head == NULL) { //this is when the list is empty i.e., NULL
        head = newNode; //make head point to the new node
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) //traverse the list till we reach the last node (next == NULL)
        { temp = temp->next; //adding the new node here
        }    
        temp->next = newNode;
    }
    printf("Inserted %d at the end.\n", value);
}

// Insert at specific position
void insertAtPosition(int value, int pos) {
    struct Node* newNode = createNode(value); //creating a new node
    if (pos == 1) { //when pos is 1 then insert at the beginning
        newNode->next = head;
        head = newNode;
        printf("Inserted %d at position %d.\n", value, pos);
        return;
    }

    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++) { //we traverse the list till we reach the pos-1 node
        temp = temp->next; //traverses the list one node at a time
    }

    if (temp == NULL) { //when the pos is invalid
        printf("Position out of range!\n");
        free(newNode);
    } else { //here we are linking the new node in between the pos-1 and pos node
        newNode->next = temp->next; 
        temp->next = newNode;
        printf("Inserted %d at position %d.\n", value, pos);
    }
}

// Delete at beginning
void deleteAtBeginning() {
    if (head == NULL) { //if the list is empty i.e., having NULL
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head; 
    head = head->next; //we move the head to the second node
    printf("Deleted %d from the beginning.\n", temp->data);
    free(temp); //we free the memory of the 1st node
}

// Delete at end
void deleteAtEnd() {
    if (head == NULL) { //is the list is epmty
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    if (head->next == NULL) { //when there is only one node
        printf("Deleted %d from the end.\n", head->data);
        free(head); //free the memory of the node
        head = NULL; //set the head value as NULL since there are no nodes in the list
        return;
    }
    while (temp->next->next != NULL){ //when there are more than one nodes, we traverse till the second last node
        temp = temp->next; //move one node at a time
    }
    printf("Deleted %d from the end.\n", temp->next->data);
    free(temp->next); //free the memory of the node
    temp->next = NULL; //set the next node to NULL
}

// Delete at specific position
void deleteAtPosition(int pos) {
    if (head == NULL) { //when there are no nodes in the list
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;

    if (pos == 1) { //when pos is 1 then it means delete from beginning
        head = head->next;
        printf("Deleted %d from position %d.\n", temp->data, pos);
        free(temp);
        return;
    }

    for (int i = 1; temp != NULL && i < pos - 1; i++){
        temp = temp->next;
    }
        
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range!\n");
        return;
    }

    struct Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    printf("Deleted %d from position %d.\n", nodeToDelete->data, pos);
    free(nodeToDelete);
}

// Display linked list
void displayList() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value, pos;
    while (1) {
        printf("1. Insert at Beginning\n");
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
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAtPosition(value, pos);
                break;
            case 4:
                deleteAtBeginning();
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;
            case 7:
                displayList();
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

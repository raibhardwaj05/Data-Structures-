#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Pointers to front and rear of the queue
struct Node* front = NULL;
struct Node* rear = NULL;

// Function to add an element to the queue (enqueue)
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation error\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    
    if (rear == NULL) {
        // Queue is empty
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d enqueued to queue\n", value);
}

// Function to remove an element from the queue (dequeue)
int dequeue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return -1; // Indicating queue is empty
    }
    struct Node* temp = front;
    int removedValue = temp->data;
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    free(temp);
    return removedValue;
}

// Function to display the queue elements
void display() {
    struct Node* temp = front;
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to test queue implementation
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    
    display();
    
    printf("Dequeued element: %d\n", dequeue());
    display();
    
    return 0;
}

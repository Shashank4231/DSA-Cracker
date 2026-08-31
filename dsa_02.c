// #include <stdio.h>
// #include <stdlib.h>

// struct Node {
//     int data;
//     struct Node* next;
// };

// struct Node* createNode(int x);

// // Function to insert a new node at the beginning of the
// // list
// struct Node* insertAtFront(struct Node* head, int new_data) {
  
//     // Create a new node with the given data
//     struct Node* new_node = createNode(new_data);

//     // Make the next of the new node point to the current
//     // head
//     new_node->next = head;

//     // Return the new node as the new head of the list
//     return new_node;
// }

// void printList(struct Node* head) {
//     struct Node* curr = head;
//     while (curr != NULL) {
//         printf(" %d", curr->data);
//         curr = curr->next;
//     }
//     printf("\n");
// }

// struct Node* createNode(int new_data) {
//     struct Node* new_node
//         = (struct Node*)malloc(sizeof(struct Node));
//     new_node->data = new_data;
//     new_node->next = NULL;
//     return new_node;
// }

// int main() {
  
//     // Create the linked list 2->3->4->5
//     struct Node* head = createNode(2);
//     head->next = createNode(3);
//     head->next->next = createNode(4);
//     head->next->next->next = createNode(5);

//     int data = 1;
//     head = insertAtFront(head, data);
//     printList(head);

//     return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>

// struct Node {
//     int data;
//     struct Node* next;
// };

// struct Node* createNode(int new_data);

// // Function appends a new node at the end and returns the
// // head.
// struct Node* insertAtEnd(struct Node* head, int new_data)
// {
//     // Create a new node
//     struct Node* new_node = createNode(new_data);

//     // If the Linked List is empty, make
//     // the new node as the head and return
//     if (head == NULL) {
//         return new_node;
//     }

//     // Store the head reference in a temporary variable
//     struct Node* last = head;

//     // Traverse till the last node
//     while (last->next != NULL) {
//         last = last->next;
//     }

//     // Change the next pointer of the last node
//     // to point to the new node
//     last->next = new_node;

//     // Return the head of the list
//     return head;
// }

// void printList(struct Node* node)
// {
//     while (node != NULL) {
//         printf(" %d", node->data);
//         node = node->next;
//     }
// }

// struct Node* createNode(int new_data)
// {
//     struct Node* new_node
//         = (struct Node*)malloc(sizeof(struct Node));
//     new_node->data = new_data;
//     new_node->next = NULL;
//     return new_node;
// }

// int main()
// {
//     // Create a linked list:
//     // 2 -> 3 -> 4 -> 5 -> 6
//     struct Node* head = createNode(2);
//     head->next = createNode(3);
//     head->next->next = createNode(4);
//     head->next->next->next = createNode(5);
//     head->next->next->next->next = createNode(6);

//     head = insertAtEnd(head, 1);

//     printList(head);

//     return 0;
// }



// #include <stdio.h>
// #include <stdlib.h>

// struct Node {
//     int data;
//     struct Node* next;
// };

// struct Node* createNode(int data);

// // Function to insert a node at a specific position in the
// // linked list
// struct Node* insertAtPosition(struct Node* head,
//                               int position, int data) {
//     struct Node* newNode = createNode(data);

//     // If inserting at the beginning
//     if (position == 1) {
//         newNode->next = head;
//         head = newNode;
//         return head;
//     }

//     struct Node* current = head;
//     for (int i = 1; i < position - 1 && current != NULL;
//          ++i) {
//         current = current->next;
//     }

//     // If the position is out of bounds
//     if (current == NULL) {
//         printf("Position is out of bounds.\n");
//         free(newNode);
//         return head;
//     }

//     newNode->next = current->next;
//     current->next = newNode;
//     return head;
// }

// void printList(struct Node* head) {
//     while (head != NULL) {
//         printf(" %d", head->data);
//         head = head->next;
//     }
//     printf("\n");
// }

// struct Node* createNode(int data) {
//     struct Node* newNode
//         = (struct Node*)malloc(sizeof(struct Node));
//     newNode->data = data;
//     newNode->next = NULL;
//     return newNode;
// }

// int main() {
  
//     // Creating the list 3->5->8->10
//     struct Node* head = createNode(3);
//     head->next = createNode(5);
//     head->next->next = createNode(8);
//     head->next->next->next = createNode(10);

//     int data = 12, pos = 2;
//     head = insertAtPosition(head, pos, data);
 
//     printList(head);

//     return 0;
// }


// #include <limits.h>
// #include <stdio.h>
// #include <stdlib.h>

// // Struct representing a node in the linked list
// typedef struct Node {
//     int data;
//     struct Node* next;
// } Node;
// Node* createNode(int new_data) {
//     Node* new_node = (Node*)malloc(sizeof(Node));
//     new_node->data = new_data;
//     new_node->next = NULL;
//     return new_node;
// }

// // Struct to implement stack using a singly linked list
// typedef struct Stack {
//     Node* head;
// } Stack;

// // Constructor to initialize the stack
// void initializeStack(Stack* stack) { stack->head = NULL; }

// // Function to check if the stack is empty
// int isEmpty(Stack* stack) {
  
//     // If head is NULL, the stack is empty
//     return stack->head == NULL;
// }

// // Function to push an element onto the stack
// void push(Stack* stack, int new_data) {
  
//     // Create a new node with given data
//     Node* new_node = createNode(new_data);

//     // Check if memory allocation for the new node failed
//     if (!new_node) {
//         printf("\nStack Overflow");
//         return;
//     }

//     // Link the new node to the current top node
//     new_node->next = stack->head;

//     // Update the top to the new node
//     stack->head = new_node;
// }

// // Function to remove the top element from the stack
// void pop(Stack* stack) {
  
//     // Check for stack underflow
//     if (isEmpty(stack)) {
//         printf("\nStack Underflow\n");
//         return;
//     }
//     else {
      
//         // Assign the current top to a temporary variable
//         Node* temp = stack->head;

//         // Update the top to the next node
//         stack->head = stack->head->next;

//         // Deallocate the memory of the old top node
//         free(temp);
//     }
// }

// // Function to return the top element of the stack
// int peek(Stack* stack) {
  
//     // If stack is not empty, return the top element
//     if (!isEmpty(stack))
//         return stack->head->data;
//     else {
//         printf("\nStack is empty");
//         return INT_MIN;
//     }
// }

// // Driver program to test the stack implementation
// int main() {
  
//     // Creating a stack
//     Stack stack;
//     initializeStack(&stack);

//     // Push elements onto the stack
//     push(&stack, 11);
//     push(&stack, 22);
//     push(&stack, 33);
//     push(&stack, 44);

//     // Print top element of the stack
//     printf("Top element is %d\n", peek(&stack));

  
//       // removing two elemements from the top
//       printf("Removing two elements...\n");
//     pop(&stack);
//     pop(&stack);

//     // Print top element of the stack
//     printf("Top element is %d\n", peek(&stack));

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// // Node structure for the linked list
// struct Node {
//     int data;
//     struct Node* next;
// };


// // Function to delete the head node
// struct Node* deleteHead(struct Node* head)
// {
//     // Base case if linked list is empty
//     if (head == NULL)
//         return NULL;

//     // Store the current head in a temporary variable
//     struct Node* temp = head;

//     // Move the head to the next node
//     head = head->next;

//     // Free the memory of the old head node
//     free(temp);

//     // Return the new head
//     return head;
// }

// // Function to print the linked list
// void printList(struct Node* head)
// {
//     while (head != NULL) {
//         printf("%d -> ", head->data);
//         head = head->next;
//     }
//     printf("NULL\n");
// }

// // Function to create a new node
// struct Node* createNode(int data)
// {
//     struct Node* node
//         = (struct Node*)malloc(sizeof(struct Node));
//     node->data = data;
//     node->next = NULL;
//     return node;
// }

// int main()
// {
//     // Creating a linked list
//     // 1 -> 2 -> 3 -> 4 -> 5 -> NULL
//     struct Node* head = createNode(1);
//     head->next = createNode(2);
//     head->next->next = createNode(3);
//     head->next->next->next = createNode(4);
//     head->next->next->next->next = createNode(5);

//     printf("Original list: ");
//     printList(head);

//     // Deleting the head node
//     head = deleteHead(head);

//     printf("List after deleting the head: ");
//     printList(head);

//     return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>

// // Node structure for the linked list
// struct Node {
//     int data;
//     struct Node* next;
// };

// // Function to remove the last node of the linked list
// struct Node* removeLastNode(struct Node* head)
// {
//     // If the list is empty, return NULL
//     if (head == NULL) {
//         return NULL;
//     }

//     // If the list has only one node, delete it and return
//     // NULL
//     if (head->next == NULL) {
//         free(head);
//         return NULL;
//     }

//     // Find the second last node
//     struct Node* second_last = head;
//     while (second_last->next->next != NULL) {
//         second_last = second_last->next;
//     }

//     // Delete the last node
//     free(second_last->next);

//     // Change next of second last
//     second_last->next = NULL;

//     return head;
// }

// void printList(struct Node* head)
// {
//     while (head != NULL) {
//         printf("%d -> ", head->data);
//         head = head->next;
//     }
//     printf("NULL\n");
// }

// // Function to create a new node
// struct Node* createNode(int data)
// {
//     struct Node* newNode
//         = (struct Node*)malloc(sizeof(struct Node));
//     newNode->data = data;
//     newNode->next = NULL;
//     return newNode;
// }

// int main()
// {
//     // Creating a static linked list
//     // 1 -> 2 -> 3 -> 4 -> 5 -> NULL
//     struct Node* head = createNode(1);
//     head->next = createNode(2);
//     head->next->next = createNode(3);
//     head->next->next->next = createNode(4);
//     head->next->next->next->next = createNode(5);

//     printf("Original list: ");
//     printList(head);

//     // Removing the last node
//     head = removeLastNode(head);

//     printf("List after removing the last node: ");
//     printList(head);

//     return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>

// // Node structure for the linked list
// struct Node {
//     int data;
//     struct Node* next;
// };

// // Function to delete a node at a given position
// struct Node* deleteNode(struct Node* head, int position){
  
//     struct Node* prev;
//     struct Node* temp = head;

//     // Base case if linked list is empty
//     if (temp == NULL)
//         return head;

//     // Case 1: Head is to be deleted
//     if (position == 1) {
//         // make next node as head and free old head
//         head = temp->next;
//         return head;
//     }

//     // Case 2: Node to be deleted is in the middle
//     // Traverse till the given position
//     for (int i = 1; temp != NULL && i < position; i++) {
//         prev = temp;
//         temp = temp->next;
//     }

//     // If the given position is found, delete node
//     if (temp != NULL) {
//         prev->next = temp->next;
//         free(temp);
//     }
//     // If the given position is not present
//     else {
//         printf("Data not present\n");
//     }

//     return head;
// }

// void printList(struct Node* head){
//     while (head != NULL) {
//         printf("%d -> ", head->data);
//         head = head->next;
//     }
//     printf("NULL\n");
// }

// // Function to create a new node
// struct Node* createNode(int data){
//     struct Node* node
//         = (struct Node*)malloc(sizeof(struct Node));
//     node->data = data;
//     node->next = NULL;
//     return node;
// }

// int main(){
//     // Creating a static linked list
//     // 1 -> 2 -> 3 -> 4 -> 5 -> NULL
//     struct Node* head = createNode(1);
//     head->next = createNode(2);
//     head->next->next = createNode(3);
//     head->next->next->next = createNode(4);
//     head->next->next->next->next = createNode(5);

//     printf("Original list: ");
//     printList(head);

//     // Deleting node at position 2
//     int position = 2;
//     head = deleteNode(head, position);

//     printf("List after deletion: ");
//     printList(head);


//     return 0;
// }

// #include <limits.h>
// #include <stdio.h>
// #include <stdlib.h>

// // Node structure representing a single node in the linked
// // list
// typedef struct Node {
//     int data;
//     struct Node* next;
// } Node;

// // Function to create a new node
// Node* createNode(int new_data)
// {
//     Node* new_node = (Node*)malloc(sizeof(Node));
//     new_node->data = new_data;
//     new_node->next = NULL;
//     return new_node;
// }

// // Structure to implement queue operations using a linked
// // list
// typedef struct Queue {

//     // Pointer to the front and the rear of the linked list
//     Node *front, *rear;
// } Queue;

// // Function to create a queue
// Queue* createQueue()
// {
//     Queue* q = (Queue*)malloc(sizeof(Queue));
//     q->front = q->rear = NULL;
//     return q;
// }

// // Function to check if the queue is empty
// int isEmpty(Queue* q)
// {

//     // If the front and rear are null, then the queue is
//     // empty, otherwise it's not
//     if (q->front == NULL && q->rear == NULL) {
//         return 1;
//     }
//     return 0;
// }

// // Function to add an element to the queue
// void enqueue(Queue* q, int new_data)
// {

//     // Create a new linked list node
//     Node* new_node = createNode(new_data);

//     // If queue is empty, the new node is both the front
//     // and rear
//     if (q->rear == NULL) {
//         q->front = q->rear = new_node;
//         return;
//     }

//     // Add the new node at the end of the queue and
//     // change rear
//     q->rear->next = new_node;
//     q->rear = new_node;
// }

// // Function to remove an element from the queue
// void dequeue(Queue* q)
// {

//     // If queue is empty, return
//     if (isEmpty(q)) {
//         printf("Queue Underflow\n");
//         return;
//     }

//     // Store previous front and move front one node
//     // ahead
//     Node* temp = q->front;
//     q->front = q->front->next;

//     // If front becomes null, then change rear also
//     // to null
//     if (q->front == NULL)
//         q->rear = NULL;

//     // Deallocate memory of the old front node
//     free(temp);
// }

// // Function to get the front element of the queue
// int getFront(Queue* q)
// {

//     // Checking if the queue is empty
//     if (isEmpty(q)) {
//         printf("Queue is empty\n");
//         return INT_MIN;
//     }
//     return q->front->data;
// }

// // Function to get the rear element of the queue
// int getRear(Queue* q)
// {

//     // Checking if the queue is empty
//     if (isEmpty(q)) {
//         printf("Queue is empty\n");
//         return INT_MIN;
//     }
//     return q->rear->data;
// }

// // Driver code
// int main()
// {
//     Queue* q = createQueue();

//     // Enqueue elements into the queue
//     enqueue(q, 10);
//     enqueue(q, 20);
    
//       printf("Queue Front: %d\n", getFront(q));
//     printf("Queue Rear: %d\n", getRear(q));

//     // Dequeue elements from the queue
//     dequeue(q);
//     dequeue(q);


//     // Enqueue more elements into the queue
//     enqueue(q, 30);
//     enqueue(q, 40);
//     enqueue(q, 50);

//     // Dequeue an element from the queue
//     dequeue(q);

//     printf("Queue Front: %d\n", getFront(q));
//     printf("Queue Rear: %d\n", getRear(q));

//     return 0;
// }

// #include <stdio.h>  
// #include <string.h>  
// #include <stdlib.h>  
   
// //Represents the node of list.  
// struct node{  
//     int data;  
//     struct node *next;  
// };  
   
// //Declaring head and tail pointer as null.  
// struct node *head = NULL;  
// struct node *tail = NULL;  
   
// //This function will add the new node at the end of the list.  
// void add(int data){  
//     //Create new node  
//     struct node *newNode = (struct node*)malloc(sizeof(struct node));  
//     newNode->data = data;  
//     //Checks if the list is empty.  
//     if(head == NULL){  
//         //If list is empty, both head and tail would point to new node.  
//         head = newNode;  
//         tail = newNode;  
//         newNode->next = head;  
//     }else {  
//         //tail will point to new node.  
//         tail->next = newNode;  
//         //New node will become new tail.  
//         tail = newNode;  
//         //Since, it is circular linked list tail will point to head.  
//         tail->next = head;  
//     }  
// }  
   
// //This function will display the nodes of circular linked list  
// void display(){  
//     struct node *current = head;  
//     if(head == NULL){  
//         printf("List is empty");  
//     }  
//     else{  
//         printf("Nodes of the circular linked list: \n");  
//          do{  
//              //Prints each node by incrementing pointer.  
//             printf("%d ", current->data);  
//             current = current->next;  
//         }while(current != head);  
//         printf("\n");  
//     }  
// }  
      
// int main()  
// {  
//     //Adds data to the list  
//    add(1);  
//    add(2);  
//    add(3);  
//    add(4);  
//    //Displays all the nodes present in the list  
//    display();  
     
//    return 0;  
// }  


// #include <stdio.h>  
// #include <string.h>  
// #include <stdlib.h>  
// #include <stdbool.h>   
   
// //Represents the node of list.  
// struct node{  
//     int data;  
//     struct node *next;  
// };  
   
// //Declaring head and tail pointer as null.  
// struct node *head = NULL;  
// struct node *tail = NULL;  
   
// //This function will add the new node at the end of the list.  
// void add(int data){  
//     //Create new node  
//     struct node *newNode = (struct node*)malloc(sizeof(struct node));  
//     newNode->data = data;  
//     //Checks if the list is empty.  
//     if(head == NULL){  
//         //If list is empty, both head and tail would point to new node.  
//         head = newNode;  
//         tail = newNode;  
//         newNode->next = head;  
//     }else {  
//         //tail will point to new node.  
//         tail->next = newNode;  
//         //New node will become new tail.  
//         tail = newNode;  
//         //Since, it is circular linked list tail will point to head.  
//         tail->next = head;  
//     }  
// }  
   
// //Searches for a node in the list  
// void search(int element) {  
//     struct node *current = head;  
//     int i = 1;  
//     bool flag = false;  
//     //Checks whether list is empty  
//     if(head == NULL) {  
//         printf("List is empty");  
//     }  
//     else {  
//          do{  
//              //Compares element to be found with each node present in the list  
//             if(current->data ==  element) {  
//                 flag = true;  
//                 break;  
//             }  
//             current = current->next;  
//             i++;  
//         }while(current != head);  
//          if(flag)  
//             printf("Element is present in the list at the position : %d", i);  
//         else  
//             printf("\nElement is not present in the list");  
//     }  
// }  
      
// int main()  
// {  
//     //Adds data to the list  
//    add(1);  
//    add(2);  
//    add(3);  
//    add(4);  
//    //Search for node 2 in the list  
//    search(2);  
//    //Search for node in the list  
//    search(7);  
     
//    return 0;  
// }  


// #include <stdio.h>
// #include <stdlib.h>

// // Define the structure for a node in the circular linked list
// struct Node {
//     int data;
//     struct Node* next;
// };

// // Function to create a new node
// struct Node* createNode(int data) {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     newNode->data = data;
//     newNode->next = newNode; // Point to itself (circular)
//     return newNode;
// }

// // Function to insert a node at the beginning
// void insertAtBeginning(struct Node** head, int data) {
//     struct Node* newNode = createNode(data);
//     if (*head == NULL) {
//         *head = newNode;
//     } else {
//         struct Node* temp = *head;
//         while (temp->next != *head) {
//             temp = temp->next;
//         }
//         temp->next = newNode;
//     }
//     newNode->next = *head;
//     *head = newNode;
// }

// // Function to insert a node at the end
// void insertAtEnd(struct Node** head, int data) {
//     struct Node* newNode = createNode(data);
//     if (*head == NULL) {
//         *head = newNode;
//     } else {
//         struct Node* temp = *head;
//         while (temp->next != *head) {
//             temp = temp->next;
//         }
//         temp->next = newNode;
//     }
//     newNode->next = *head;
// }

// // Function to insert a node at a given position
// void insertAtPosition(struct Node** head, int data, int position) {
//     if (position == 0) {
//         insertAtBeginning(head, data);
//         return;
//     }
    
//     struct Node* newNode = createNode(data);
//     struct Node* temp = *head;

//     for (int i = 0; i < position - 1; i++) {
//         if (temp->next == *head) {
//             printf("Position is out of bounds. Inserting at the end instead.\n");
//             insertAtEnd(head, data);
//             return;
//         }
//         temp = temp->next;
//     }
    
//     newNode->next = temp->next;
//     temp->next = newNode;
// }

// // Function to display the circular linked list
// void displayList(struct Node* head) {
//     if (head == NULL) {
//         printf("List is empty.\n");
//         return;
//     }
    
//     struct Node* temp = head;
//     do {
//         printf("%d -> ", temp->data);
//         temp = temp->next;
//     } while (temp != head);
//     printf("(head)\n");
// }

// // Main function to test the circular linked list operations
// int main() {
//     struct Node* head = NULL;

//     insertAtEnd(&head, 10);
//     insertAtEnd(&head, 20);
//     insertAtBeginning(&head, 5);
//     insertAtPosition(&head, 15, 2); // Inserting at position 2
//     insertAtPosition(&head, 25, 10); // Position out of bounds, will insert at end

//     printf("Circular Linked List: ");
//     displayList(head);

//     return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>

// // Define the structure for a node in the circular linked list
// struct Node {
//     int data;
//     struct Node* next;
// };

// // Function to create a new node
// struct Node* createNode(int data) {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     newNode->data = data;
//     newNode->next = newNode; // Point to itself
//     return newNode;
// }

// // Function to insert a node at the end of the circular linked list
// void insertEnd(struct Node** head, int data) {
//     struct Node* newNode = createNode(data);
//     if (*head == NULL) {
//         *head = newNode;
//     } else {
//         struct Node* temp = *head;
//         while (temp->next != *head) {
//             temp = temp->next;
//         }
//         temp->next = newNode;
//     }
//     newNode->next = *head; // Make it circular
// }

// // Function to delete a node from the beginning
// void deleteBeginning(struct Node** head) {
//     if (*head == NULL) {
//         printf("List is empty. Nothing to delete.\n");
//         return;
//     }
    
//     struct Node* temp = *head;
//     if (temp->next == *head) {
//         free(temp);
//         *head = NULL; // List becomes empty
//     } else {
//         struct Node* last = *head;
//         while (last->next != *head) {
//             last = last->next;
//         }
//         last->next = temp->next; // Last node points to second node
//         *head = temp->next; // Move head to second node
//         free(temp);
//     }
// }

// // Function to delete a node from the end
// void deleteEnd(struct Node** head) {
//     if (*head == NULL) {
//         printf("List is empty. Nothing to delete.\n");
//         return;
//     }
    
//     struct Node* temp = *head;
//     if (temp->next == *head) {
//         free(temp);
//         *head = NULL; // List becomes empty
//     } else {
//         struct Node* secondLast = NULL;
//         while (temp->next != *head) {
//             secondLast = temp;
//             temp = temp->next;
//         }
//         secondLast->next = *head; // Second last points to head
//         free(temp);
//     }
// }

// // Function to delete a node at a given position
// void deleteAtPosition(struct Node** head, int position) {
//     if (*head == NULL) {
//         printf("List is empty. Nothing to delete.\n");
//         return;
//     }
    
//     struct Node* temp = *head;

//     if (position == 0) {
//         deleteBeginning(head);
//         return;
//     }

//     for (int i = 0; temp != NULL && i < position - 1; i++) {
//         temp = temp->next;
//         if (temp == *head) {
//             printf("Position exceeds the length of the list.\n");
//             return;
//         }
//     }

//     if (temp == NULL || temp->next == *head) {
//         printf("Position exceeds the length of the list.\n");
//         return;
//     }

//     struct Node* toDelete = temp->next;
//     temp->next = toDelete->next;

//     if (toDelete == *head) {
//         *head = toDelete->next; // Update head if needed
//     }

//     free(toDelete);
// }

// // Function to print the circular linked list
// void printList(struct Node* head) {
//     if (head == NULL) {
//         printf("List is empty.\n");
//         return;
//     }

//     struct Node* temp = head;
//     do {
//         printf("%d -> ", temp->data);
//         temp = temp->next;
//     } while (temp != head);
//     printf("(head)\n");
// }

// // Main function to demonstrate the circular linked list operations
// int main() {
//     struct Node* head = NULL;

//     insertEnd(&head, 10);
//     insertEnd(&head, 20);
//     insertEnd(&head, 30);
//     insertEnd(&head, 40);
    
//     printf("Circular Linked List: ");
//     printList(head);

//     deleteBeginning(&head);
//     printf("After deleting from beginning: ");
//     printList(head);

//     deleteEnd(&head);
//     printf("After deleting from end: ");
//     printList(head);

//     deleteAtPosition(&head, 1);
//     printf("After deleting at position 1: ");
//     printList(head);

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// // Structure for a node in the doubly circular linked list
// struct Node {
//     int data;
//     struct Node* next;
//     struct Node* prev;
// };

// // Function to create a new node
// struct Node* createNode(int data) {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     newNode->data = data;
//     newNode->next = newNode; // Point to itself
//     newNode->prev = newNode; // Point to itself
//     return newNode;
// }

// // Function to insert a node at the end of the doubly circular linked list
// void insertEnd(struct Node** head, int data) {
//     struct Node* newNode = createNode(data);
//     if (*head == NULL) {
//         *head = newNode;
//     } else {
//         struct Node* tail = (*head)->prev; // Get the tail (last node)
//         tail->next = newNode; // Link last node to new node
//         newNode->prev = tail; // Link new node back to last node
//         newNode->next = *head; // Link new node to head
//         (*head)->prev = newNode; // Link head back to new node
//     }
// }

// // Function to display the elements of the doubly circular linked list
// void displayList(struct Node* head) {
//     if (head == NULL) {
//         printf("List is empty.\n");
//         return;
//     }
//     struct Node* temp = head;
//     do {
//         printf("%d ", temp->data);
//         temp = temp->next;
//     } while (temp != head);
//     printf("\n");
// }

// // Main function to demonstrate the doubly circular linked list
// int main() {
//     struct Node* head = NULL;

//     // Inserting elements into the doubly circular linked list
//     insertEnd(&head, 10);
//     insertEnd(&head, 20);
//     insertEnd(&head, 30);
//     insertEnd(&head, 40);

//     // Displaying the elements of the list
//     printf("Doubly Circular Linked List: ");
//     displayList(head);

//     return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>

// // Define the structure for a node in the doubly circular linked list
// struct Node {
//     int data;
//     struct Node* next;
//     struct Node* prev;
// };

// // Function to create a new node
// struct Node* createNode(int data) {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     newNode->data = data;
//     newNode->next = newNode; // Point to itself
//     newNode->prev = newNode; // Point to itself
//     return newNode;
// }

// // Function to insert a node at the end of the doubly circular linked list
// void insertEnd(struct Node** head, int data) {
//     struct Node* newNode = createNode(data);
//     if (*head == NULL) {
//         *head = newNode;
//     } else {
//         struct Node* tail = (*head)->prev;
//         tail->next = newNode;
//         newNode->prev = tail;
//         newNode->next = *head;
//         (*head)->prev = newNode;
//     }
// }

// // Function to search for an element in the doubly circular linked list
// int searchElement(struct Node* head, int key) {
//     if (head == NULL) {
//         return 0; // List is empty
//     }
    
//     struct Node* current = head;
//     do {
//         if (current->data == key) {
//             return 1; // Element found
//         }
//         current = current->next;
//     } while (current != head);
    
//     return 0; // Element not found
// }

// // Function to display the list (for testing purposes)
// void displayList(struct Node* head) {
//     if (head == NULL) {
//         printf("List is empty.\n");
//         return;
//     }
    
//     struct Node* current = head;
//     do {
//         printf("%d ", current->data);
//         current = current->next;
//     } while (current != head);
//     printf("\n");
// }

// // Main function to demonstrate the functionality
// int main() {
//     struct Node* head = NULL;

//     // Inserting elements into the doubly circular linked list
//     insertEnd(&head, 10);
//     insertEnd(&head, 20);
//     insertEnd(&head, 30);
//     insertEnd(&head, 40);

//     // Display the list
//     printf("Doubly Circular Linked List: ");
//     displayList(head);

//     // Searching for elements
//     int searchKey = 20;
//     if (searchElement(head, searchKey)) {
//         printf("Element %d found in the list.\n", searchKey);
//     } else {
//         printf("Element %d not found in the list.\n", searchKey);
//     }

//     searchKey = 50;
//     if (searchElement(head, searchKey)) {
//         printf("Element %d found in the list.\n", searchKey);
//     } else {
//         printf("Element %d not found in the list.\n", searchKey);
//     }

//     return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>

// // Structure for a node in the doubly circular linked list
// struct Node {
//     int data;
//     struct Node* next;
//     struct Node* prev;
// };

// // Function to create a new node
// struct Node* createNode(int data) {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     newNode->data = data;
//     newNode->next = newNode;
//     newNode->prev = newNode;
//     return newNode;
// }

// // Function to insert a node at the beginning
// void insertAtBeginning(struct Node** head, int data) {
//     struct Node* newNode = createNode(data);
//     if (*head == NULL) {
//         *head = newNode;
//     } else {
//         struct Node* tail = (*head)->prev;
//         newNode->next = *head;
//         newNode->prev = tail;
//         tail->next = newNode;
//         (*head)->prev = newNode;
//     }
//     *head = newNode;
// }

// // Function to insert a node at the end
// void insertAtEnd(struct Node** head, int data) {
//     struct Node* newNode = createNode(data);
//     if (*head == NULL) {
//         *head = newNode;
//     } else {
//         struct Node* tail = (*head)->prev;
//         tail->next = newNode;
//         newNode->prev = tail;
//         newNode->next = *head;
//         (*head)->prev = newNode;
//     }
// }

// // Function to insert a node at a given position
// void insertAtPosition(struct Node** head, int data, int position) {
//     if (position == 0) {
//         insertAtBeginning(head, data);
//         return;
//     }

//     struct Node* newNode = createNode(data);
//     struct Node* current = *head;
//     int count = 0;

//     if (*head == NULL) {
//         // If the list is empty and position is not zero, do nothing
//         return;
//     }

//     while (current->next != *head && count < position - 1) {
//         current = current->next;
//         count++;
//     }

//     newNode->next = current->next;
//     newNode->prev = current;

//     current->next->prev = newNode;
//     current->next = newNode;
// }

// // Function to display the list
// void displayList(struct Node* head) {
//     if (head == NULL) {
//         printf("List is empty.\n");
//         return;
//     }

//     struct Node* temp = head;
//     do {
//         printf("%d ", temp->data);
//         temp = temp->next;
//     } while (temp != head);
//     printf("\n");
// }

// // Main function to demonstrate the functionality
// int main() {
//     struct Node* head = NULL;

//     insertAtEnd(&head, 10);
//     insertAtEnd(&head, 20);
//     insertAtBeginning(&head, 5);
//     insertAtPosition(&head, 15, 2); // Insert 15 at position 2

//     printf("Doubly Circular Linked List: ");
//     displayList(head);

//     return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>

// // Define the structure for a node in the doubly circular linked list
// struct Node {
//     int data;
//     struct Node* next;
//     struct Node* prev;
// };

// // Function to create a new node
// struct Node* createNode(int data) {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     newNode->data = data;
//     newNode->next = newNode;
//     newNode->prev = newNode;
//     return newNode;
// }

// // Function to insert a node at the end of the list
// void insertEnd(struct Node** head, int data) {
//     struct Node* newNode = createNode(data);
//     if (*head == NULL) {
//         *head = newNode;
//     } else {
//         struct Node* tail = (*head)->prev;
//         tail->next = newNode;
//         newNode->prev = tail;
//         newNode->next = *head;
//         (*head)->prev = newNode;
//     }
// }

// // Function to delete a node from the beginning
// void deleteFromBeginning(struct Node** head) {
//     if (*head == NULL) {
//         printf("List is empty.\n");
//         return;
//     }
//     struct Node* temp = *head;
//     if (temp->next == *head) {
//         free(temp);
//         *head = NULL;
//     } else {
//         struct Node* tail = temp->prev;
//         tail->next = temp->next;
//         temp->next->prev = tail;
//         *head = temp->next;
//         free(temp);
//     }
// }

// // Function to delete a node from the end
// void deleteFromEnd(struct Node** head) {
//     if (*head == NULL) {
//         printf("List is empty.\n");
//         return;
//     }
//     struct Node* tail = (*head)->prev;
//     if (tail == *head) {
//         free(tail);
//         *head = NULL;
//     } else {
//         struct Node* newTail = tail->prev;
//         newTail->next = *head;
//         (*head)->prev = newTail;
//         free(tail);
//     }
// }

// // Function to delete a node from a specific position
// void deleteFromPosition(struct Node** head, int position) {
//     if (*head == NULL) {
//         printf("List is empty.\n");
//         return;
//     }
//     struct Node* current = *head;
//     int count = 0;

//     // Traverse to the desired position
//     while (count < position) {
//         current = current->next;
//         count++;
//         if (current == *head) {
//             printf("Position out of bounds.\n");
//             return;
//         }
//     }

//     // Deleting the node
//     if (current->next == current) { // Only one node in the list
//         free(current);
//         *head = NULL;
//     } else {
//         current->prev->next = current->next;
//         current->next->prev = current->prev;
//         if (current == *head) {
//             *head = current->next; // Update head if necessary
//         }
//         free(current);
//     }
// }

// // Function to display the list
// void displayList(struct Node* head) {
//     if (head == NULL) {
//         printf("List is empty.\n");
//         return;
//     }
//     struct Node* temp = head;
//     do {
//         printf("%d ", temp->data);
//         temp = temp->next;
//     } while (temp != head);
//     printf("\n");
// }

// // Main function to demonstrate the functionality
// int main() {
//     struct Node* head = NULL;

//     // Inserting elements into the list
//     insertEnd(&head, 10);
//     insertEnd(&head, 20);
//     insertEnd(&head, 30);
//     insertEnd(&head, 40);
//     insertEnd(&head, 50);

//     printf("Initial list: ");
//     displayList(head);

//     // Deleting from the beginning
//     deleteFromBeginning(&head);
//     printf("After deleting from beginning: ");
//     displayList(head);

//     // Deleting from the end
//     deleteFromEnd(&head);
//     printf("After deleting from end: ");
//     displayList(head);

//     // Deleting from a specific position
//     int position = 1; // Change this value to test different positions
//     deleteFromPosition(&head, position);
//     printf("After deleting from position %d: ", position);
//     displayList(head);

//     return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>

// struct Node {
//     int coeff;
//     int pow;
//     struct Node* next;
// };

// struct Node* createNode(int c, int p);

// struct Node* addPolynomial(struct Node* head1, struct Node* head2) {

    
//     if (head1 == NULL) return head2;
//     if (head2 == NULL) return head1;
    
    
//     if (head1->pow > head2->pow) {
//         struct Node* nextPtr = 
//           addPolynomial(head1->next, head2);
//         head1->next = nextPtr;
//         return head1;
//     }

    
//     else if (head1->pow < head2->pow) {
//         struct Node* nextPtr = 
//           addPolynomial(head1, head2->next);
//         head2->next = nextPtr;
//         return head2;
//     }

    
//     struct Node* nextPtr = 
//           addPolynomial(head1->next, head2->next);
//     head1->coeff += head2->coeff;
//     head1->next = nextPtr;
//     return head1;
// }


// void printList(struct Node* head) {
//     struct Node* curr = head;

//     while (curr != NULL) {
//         printf("%d,%d ", curr->coeff, curr->pow);
//         curr = curr->next;

//     }

//     printf("\n");
// }

// struct Node* createNode(int c, int p) {
//     struct Node* newNode = 
//         (struct Node*)malloc(sizeof(struct Node));
//     newNode->coeff = c;
//     newNode->pow = p;
//     newNode->next = NULL;
//     return newNode;
// }


// int main() {
    
//     // 1st polynomial: 5x^2+4x^1+2x^0
//     struct Node* head1 = createNode(5, 2);
//     head1->next = createNode(4, 1);
//     head1->next->next = createNode(2, 0);

//     // 2nd polynomial: -5x^1-5x^0
//     struct Node* head2 = createNode(-5, 1);
//     head2->next = createNode(-5, 0);

//     struct Node* head = addPolynomial(head1, head2);

//     printList(head);

//     return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>

// // Define the structure for a tree node
// struct Node {
//     int data;
//     struct Node* left;
//     struct Node* right;
// };

// // Function to create a new node
// struct Node* createNode(int data) {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     newNode->data = data;
//     newNode->left = NULL;
//     newNode->right = NULL;
//     return newNode;
// } 

// // Function to insert a new node into the BST
// struct Node* insert(struct Node* root, int data) {
//     // If the tree is empty, return a new node
//     if (root == NULL) {
//         return createNode(data);
//     }

//     // Otherwise, recur down the tree
//     if (data < root->data) {
//         root->left = insert(root->left, data);
//     } else if (data > root->data) {
//         root->right = insert(root->right, data);
//     }

//     // Return the unchanged node pointer
//     return root;
// }

// // Function to search for a value in the BST
// struct Node* search(struct Node* root, int data) {
//     // Base Cases: root is null or data is present at root
//     if (root == NULL || root->data == data) {
//         return root;
//     }

//     // Data is greater than root's data
//     if (data > root->data) {
//         return search(root->right, data);
//     }

//     // Data is smaller than root's data
//     return search(root->left, data);
// }

// // Function for inorder traversal of the BST
// void inorderTraversal(struct Node* root) {
//     if (root != NULL) {
//         inorderTraversal(root->left);
//         printf("%d ", root->data);
//         inorderTraversal(root->right);
//     }
// }

// // Main function to demonstrate the BST
// int main() {
//     struct Node* root = NULL;

//     // Insert values into the BST
//     root = insert(root, 50);
//     insert(root, 30);
//     insert(root, 20);
//     insert(root, 40);
//     insert(root, 70);
//     insert(root, 60);
//     insert(root, 80);

//     // Print inorder traversal of the BST
//     printf("Inorder traversal of the BST: ");
//     inorderTraversal(root);
//     printf("\n");

//     // Search for a value
//     int searchValue = 40;
//     struct Node* foundNode = search(root, searchValue);
//     if (foundNode != NULL) {
//         printf("Value %d found in the BST.\n", searchValue);
//     } else {
//         printf("Value %d not found in the BST.\n", searchValue);
//     }

//     return 0;
// }
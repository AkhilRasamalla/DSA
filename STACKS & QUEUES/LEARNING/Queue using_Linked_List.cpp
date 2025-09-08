// Function to push an element into the queue.
void MyQueue::push(int x) {
    QueueNode* newNode = new QueueNode(x);
    if (rear == NULL) {   // queue empty
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

// Function to pop front element from the queue.
int MyQueue::pop() {
    if (front == NULL) {
        return -1;  // queue empty
    }
    
    int val = front->data;
    QueueNode* temp = front;
    front = front->next;
    
    if (front == NULL) {
        rear = NULL;  // queue became empty
    }
    
    delete temp;
    return val;
}

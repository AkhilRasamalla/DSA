class MyStack {
private:
    StackNode* top;

public:
    MyStack() { top = NULL; }

    void push(int x) {
        StackNode* newNode = new StackNode(x); // already defined in Driver.cpp
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (top == NULL) {
            return -1;  // stack is empty
        }
        int val = top->data;
        StackNode* temp = top;
        top = top->next;
        delete temp;
        return val;
    }
};

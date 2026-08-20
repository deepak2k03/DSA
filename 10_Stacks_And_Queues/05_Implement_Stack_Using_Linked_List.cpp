/* Structure of linked list Node
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};*/

class myStack {
    Node* top;
    int siz;

  public:
    myStack() {
        // Initialize your data members
        top = NULL;
        siz=0;
    }

    bool isEmpty() {
        // check if the stack is empty
        return siz==0;
    }

    void push(int x) {
        // Adds an element x at the top of the stack
        Node* temp = new Node(x);
        temp->next=top;
        top=temp;
        siz++;
    }

    void pop() {
        // Removes the top element of the stack
        Node* temp = top;
        top=top->next;
        delete temp;
        siz--;
    }

    int peek() {
        // Returns the top element of the stack
        // If stack is empty, return -1
        if(siz) return top->data;
        return -1;
    }

    int size() {
        // Returns the current size of the stack
        return siz;
    }
};
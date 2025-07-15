// User function Template for C++

/*
class Node{
public:
    Node* prev;
    int data;
    Node* next;

    Node()
    {
        prev = NULL;
        data = 0;
        next = NULL;
    }

    Node(int value)
    {
        prev = NULL;
        data = value;
        next = NULL;
    }
};*/

class Solution {
  public:
    Node* constructDLL(vector<int>& arr) {
        // Create the head node
        Node* head = new Node(arr[0]);
        Node* ptr = head;

        for(int i = 1; i < arr.size(); i++) {
            Node* temp = new Node(arr[i]);
            ptr->next = temp;
            temp->prev = ptr;
            ptr = temp;
        }

        return head;
    }
};

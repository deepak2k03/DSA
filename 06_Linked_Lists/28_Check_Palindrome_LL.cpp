/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution {
  public:
    Node* reverseList(struct Node* head) {
        // code here
        Node* temp=head;
        Node* prev=NULL;
        while(temp!=NULL){
            auto front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head) {
        // Your code here
        if(head==NULL || head->next==NULL) return true;
        Node* slow=head;
        Node* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        Node* newHead=reverseList(slow->next);
        Node* first=head;
        Node* second=newHead;
        while(second!=NULL){
            if(first->data!=second->data){
                reverseList(newHead);
                return false;
            }
            first=first->next;
            second=second->next;
        }
        reverseList(newHead);
        return true;
    }
};
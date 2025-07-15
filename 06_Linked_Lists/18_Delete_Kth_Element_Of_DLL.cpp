/* Structure of Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
  public:
    Node* deleteHead(Node *head) {
        if(head==NULL||head->next==NULL) return NULL;
        Node* temp=head;
        head=head->next;
        head->prev=NULL;
        temp->next=NULL;
        delete temp;
        return head;
    }
    
    Node* deleteLastNode(Node *head) {
        if(head==NULL||head->next==NULL) return NULL;
        Node* temp=head;
        while(temp->next!=NULL) temp=temp->next;
        temp->prev->next=NULL;
        temp->prev=NULL;
        delete temp;
        return head;
    }
    // Function to delete a node at given position.
    Node* deleteNode(Node* head, int x) {
        // Your code here
        if(head==NULL) return NULL;
        Node* temp=head;
        int cnt=0;
        while(temp!=NULL){
            cnt++;
            if(cnt==x) break;
            temp=temp->next;
        }
        Node* previous=temp->prev;
        Node* front=temp->next;
        if(previous==NULL && front==NULL){
            delete temp;
            return NULL;
        }
        else if(previous==NULL) return deleteHead(head);
        else if(front==NULL) return deleteLastNode(head);
        else{
            previous->next=front;
            front->prev=previous;
            temp->next=NULL;
            temp->prev=NULL;
            delete temp;
        }
        return head;
    }
};
// User function Template for C++

/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head, int key) {
        // Write your code here
        Node* temp=*head;
        while(temp!=NULL){
            if(temp->data==key){
                if(temp==*head) *head=(*head)->next;
                Node* nextNode=temp->next;
                Node* prevNode=temp->prev;
                if(nextNode) nextNode->prev=prevNode;
                if(prevNode) prevNode->next=nextNode;
                delete temp;
                temp=nextNode;
            }
            else temp=temp->next;
        }
    }
};
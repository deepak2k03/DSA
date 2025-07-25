/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        if(head==NULL || head->next==NULL) return head;
        Node* zeroHead=new Node(69);
        Node* oneHead=new Node(69);
        Node* twoHead=new Node(69);
        Node* zero=zeroHead;
        Node* one=oneHead;
        Node* two=twoHead;
        Node* temp=head;
        while(temp!=NULL){
            if(temp->data==0){
                zero->next=temp;
                zero=zero->next;
            }
            else if(temp->data==1){
                one->next=temp;
                one=one->next;
            }
            else{
                two->next=temp;
                two=two->next;
            }
            temp=temp->next;
        }
        if (oneHead->next != NULL) zero->next = oneHead->next;
        else zero->next = twoHead->next;
        if (twoHead->next != NULL) one->next = twoHead->next;
        else one->next = NULL;
        two->next = NULL;
        delete zeroHead;
        delete oneHead;
        delete twoHead;
        return zeroHead->next;
    }
};
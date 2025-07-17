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
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        // Code here
        auto slow=head;
        auto fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                int c=1;
                slow=slow->next; //imp
                while(slow!=fast){
                    c++;
                    slow=slow->next;
                }
                return c;
            }
        }
        return 0;
    }
};
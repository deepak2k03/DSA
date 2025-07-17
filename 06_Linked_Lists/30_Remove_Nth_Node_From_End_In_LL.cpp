/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    ListNode* fast=A;
    ListNode* slow=A;
     for (int i=0;i<B;i++) {
        if (fast == NULL) break;
        fast = fast->next;
    }
    if(fast==NULL) return A->next;
    while(fast->next!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    ListNode* delNode=slow->next;
    slow->next=slow->next->next;
    delete delNode;
    return A;
}

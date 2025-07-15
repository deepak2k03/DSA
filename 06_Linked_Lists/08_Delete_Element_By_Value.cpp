Node* deleteFirstMatch(Node* head, int val) {
    if (head == NULL) return NULL;

    // Case 1: head itself matches
    if (head->data == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* prev = head;
    Node* curr = head->next;

    while (curr != NULL) {
        if (curr->data == val) {
            prev->next = curr->next;
            delete curr;
            break;
        }
        prev = curr;
        curr = curr->next;
    }

    return head;
}

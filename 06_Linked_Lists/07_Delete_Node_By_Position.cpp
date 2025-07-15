/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

Node* deleteNode(Node* head, int pos)
{
    if (head == NULL) return NULL;

    // Case 0: Delete head
    if (pos == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;  // ? use delete
        return head;
    }

    int c = 0;
    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL) {
        if (c == pos) {
            if (prev != NULL)
                prev->next = temp->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
        c++;
    }

    return head;
}

/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/

class Solution {
  public:
    Node *removeDuplicates(Node *head) {
        if (!head) return head;

        Node* curr = head;
        while (curr && curr->next) {
            if (curr->data == curr->next->data) {
                // Remove duplicate
                Node* dup = curr->next;
                curr->next = dup->next;
                if (dup->next) dup->next->prev = curr;
                delete dup; 
            } else {
                curr = curr->next; // move to next node
            }
        }
        return head;
    }
};

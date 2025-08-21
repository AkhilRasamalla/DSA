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
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        // Write your code here
        Node* temp = *head_ref;
        while(temp != NULL){
            if(temp->data==x){
                if(temp==*head_ref)
                *head_ref=(*head_ref)->next;
                
                Node* nextNode=temp->next;
                Node* prevNode=temp->prev;
                if(nextNode != NULL)
                nextNode->prev =prevNode;
                if(prevNode != NULL)
                prevNode->next=nextNode;
                delete temp;
                temp=nextNode;
                
            }
            else{
                temp = temp->next;
            }
            
        }
       // return *head_ref;
    }
};
/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
  Node* reverse(Node* head){
      Node* prev = NULL, *next=NULL,*current = head;
      while(current != NULL){
          next = current->next;
          current->next = prev;
          prev = current;
          current = next;
      }
      return prev;
      
  }
  
    Node* addOne(Node* head) {
        // Your Code here
        Node* newHead=reverse(head);
        Node* current = newHead, *prev =NULL,*current1 = newHead;
        
        int carry = 0;
        while(current != NULL){
            int sum = 0;
            if(prev==NULL){
                sum = current->data +1;
                
            }else{
                sum = current->data + carry;
                
            }
            carry = sum/10;
            current->data = sum%10;
            prev = current;
            current = current->next;
            
        }
        if(carry ==1){
            Node* newNode = new Node(1);
            prev->next = newNode;
            
        }
        return reverse(current1);
        // return head of list after adding one
    }
};
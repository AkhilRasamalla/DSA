/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
    private:
    int findLength(Node* slow ,Node*fast){
        int count =1;
        fast=fast->next;
        while(slow != fast){
            count++;
            fast=fast->next;
        }
        return count;
    }
  public:
    int lengthOfLoop(Node *head) {
        // Code here
         Node* slow = head;
         Node* fast = head;
         while(fast != NULL && fast->next != NULL){
             slow = slow->next;
             fast = fast->next->next;
             if(slow == fast){
                 return findLength(slow,fast);
             }
                //  slow = head;
                //  while(slow != fast){
                //      slow = slow->next;
                //      fast = fast->next;
                //  }
                // //  int count =1;
                // //  Node*temp = slow->next;
                // //  while(temp != slow){
                // //      count++;
                // //      temp=temp->next;
                // //  }
                // //  return count;
                 //}
         }
         return 0;
    }
};
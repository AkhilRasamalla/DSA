/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode* reverseList(ListNode* head) {
        // ListNode* curr = head;
        // ListNode* prev = nullptr;
        // ListNode* next;
        // while(curr != nullptr){

        //     next = curr->next;
        //     curr->next = prev;

        //     prev = curr;
        //     curr = next;

        // }
        // return prev;
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* newHead = reverseList(head->next);

        head->next->next = head;

        head->next = NULL;

        return newHead;
    }

public:
    bool isPalindrome(ListNode* head) {
        // ListNode* rev = reverse(head.begin(), head.end());
        // ListNode* temp = head;
        // while (temp != NULL) {
        //     temp = temp->next;
        // }
        // if (temp == rev) {
        //     return true;
        // }
        // return false;
        if(head == NULL || head->next == NULL)
        return true;

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

        }
        ListNode* newHead = reverseList(slow->next);
        ListNode* first = head;
        ListNode* second=newHead;
        while(second != NULL)
        {
            if(first->val != second->val)
            {
                reverseList(newHead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reverseList(newHead);
        return true;
    }
};
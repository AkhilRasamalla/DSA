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
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head; // 0 or 1 node, no change

        ListNode* odd = head;              // pointer for odd nodes
        ListNode* even = head->next;       // pointer for even nodes
        ListNode* evenHead = even;         // store start of even list

        while (even && even->next) {
            odd->next = even->next;        // link odd to next odd
            odd = odd->next;               // move odd forward
            even->next = odd->next;        // link even to next even
            even = even->next;             // move even forward
        }

        odd->next = evenHead;              // attach even list at end
        return head;
    }
};

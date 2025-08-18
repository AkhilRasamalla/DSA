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
    ListNode* sortList(ListNode* head) {
        // base case
        if (!head || !head->next) return head;

        // step 1: split the list into two halves
        ListNode* mid = getMiddle(head);
        ListNode* rightHalf = mid->next;
        mid->next = nullptr;  // break the list

        // step 2: recursively sort both halves
        ListNode* left = sortList(head);
        ListNode* right = sortList(rightHalf);

        // step 3: merge two sorted halves
        return merge(left, right);
    }

private:
    // find middle of linked list (slow-fast pointer)
    ListNode* getMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // merge two sorted linked lists
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        // attach remaining nodes
        if (l1) tail->next = l1;
        if (l2) tail->next = l2;

        return dummy.next;
    }
};

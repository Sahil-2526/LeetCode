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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;

        ListNode* one = list1;
        ListNode* two = list2;

        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        while (one != nullptr && two != nullptr) {
            ListNode* curr;

            if (one->val <= two->val) {
                curr = one;
                one = one->next;
            } else {
                curr = two;
                two = two->next;
            }

            if (head == nullptr) {
                head = tail = curr;
            } else {
                tail->next = curr;
                tail = curr;
            }
        }

        tail->next = (one != nullptr) ? one : two;

        return head;
    }
};
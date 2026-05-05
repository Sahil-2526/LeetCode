class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        ListNode* q = head;
        int count = 1;
        while (q->next != NULL) {
            q = q->next;
            count++;
        }
        k = k % count;
        if (k == 0) return head;
        q->next = head;
        int steps = count - k;
        ListNode* p = head;

        for (int i = 1; i < steps; i++) {
            p = p->next;
        }

        ListNode* newHead = p->next;
        p->next = NULL;

        return newHead;
    }
};
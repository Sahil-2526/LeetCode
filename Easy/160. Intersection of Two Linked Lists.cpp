class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p = headA;
        int i = 0;
        while (p != NULL) {
            i++;
            p = p->next;
        }

        ListNode* q = headB;
        int j = 0;
        while (q != NULL) {
            j++;
            q = q->next;
        }

        p = headA;
        q = headB;

        if (i > j) {
            int diff = i - j;
            while (diff--) {
                p = p->next;
            }
        } else {
            int diff = j - i;
            while (diff--) {
                q = q->next;
            }
        }

        while (p != q) {
            p = p->next;
            q = q->next;
        }

        return p; 
    }
}; 
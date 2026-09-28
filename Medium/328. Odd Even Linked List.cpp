class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode *ev = head, *od = head->next, *p = head->next->next;
        ListNode *odstrt = head->next;

        int i = 0;

        while(p != NULL) {
            if(i % 2 == 0) {
                ev->next = p;
                ev = p;
            }
            else {
                od->next = p;
                od = p;
            }

            i++;
            p = p->next;
        }

        ev->next = odstrt;
        od->next = NULL;    
        return head;
    }
};
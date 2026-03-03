class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        if (!head) return head;

        ListNode* p = head;
        ListNode* save = nullptr;   
        int count = 0;

        while (p != nullptr) {
            while (p->next!=nullptr && p->val == p->next->val) {
                p = p->next;
                count++;
            }

            if (count > 0) {
                if (save == nullptr) {
                    head = p->next;
                } else {
                    save->next = p->next;
                }
            } else {
                save = p;
            }

            p = p->next;
            count = 0;
        }

        return head;
    }
};
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* run = head;
        ListNode* prev = NULL;
        while(run != NULL && run->val < x){
            prev = run;
            run = run->next;
        }
        ListNode* p = prev;
        ListNode* q = run;
        while(run != NULL && run->next != NULL){
            if(run->next->val < x){
                ListNode* mid = run->next;
                run->next = mid->next;
                if(p == NULL){
                    mid->next = head;
                    head = mid;
                    p = mid;
                }
                else{
                    mid->next = p->next;
                    p->next = mid;
                    p = mid;
                }
            }
            else{
                run = run->next;
            }
        }

        return head;
    }
};
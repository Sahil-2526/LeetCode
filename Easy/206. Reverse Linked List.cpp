class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head ->next == NULL) return head;
        ListNode *l=head, *r=head->next->next, *mid=head->next;
        l->next = NULL;
        while(r != NULL){
            mid->next = l;
            l = mid;
            mid = r;
            r = r->next;
        }
        if(mid != NULL)
            mid->next = l;
        
        return mid;
    }
};
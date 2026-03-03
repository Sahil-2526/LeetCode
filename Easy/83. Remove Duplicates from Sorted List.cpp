class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p = head;
        ListNode* save = head;   
        while (p != nullptr) {
            if(p->next==nullptr){
                save->next=nullptr;
            }
            else if(p->next->val!=save->val){
                save->next=p->next;
                save=p->next;
            }
            p=p->next;
    }
    return head; }
};
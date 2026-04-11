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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p=head;
        for(int i=0;i<n;i++){
            p=p->next;
        }

        if(p==NULL){
            head=head->next;
            return head;
        }

        ListNode * ope=head;
        while(p->next!=NULL){
            ope=ope->next;
            p=p->next;
        }

        ope->next=ope->next->next;

        return head;
        
    }
};
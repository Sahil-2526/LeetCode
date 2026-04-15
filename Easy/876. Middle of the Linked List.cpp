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
    ListNode* middleNode(ListNode* head) {
        int k=0;
        ListNode* q=head;
        while(q->next!=NULL){
            q=q->next;
            k++;
        }

        ListNode* p=head;
        for(int i=0;i<(k+1)/2;i++){
            p=p->next;
        }

        return p;
    }
};
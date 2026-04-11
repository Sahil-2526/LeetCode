

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                slow = head; 
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};

// start -----L----- loop start ----------C---------- loop end 
//slow,fast
//                      slow --------L---- fast ---x----------
//                       ---------x------slow,fast------L------
// after L turn they will reach loop start
//slow ------L------                    fast---------L------
//                    slow,fast
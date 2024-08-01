class Solution {
public:
    ListNode* reverseList(ListNode* head) {            
        if (!head) {
            return head;
        }

        ListNode *prev = nullptr;
        ListNode *temp = head;

        while (temp->next) {
            ListNode *next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }

        temp->next = prev;
        return temp;
    }
};

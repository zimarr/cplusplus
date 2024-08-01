class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while (head && head->val == val) {
            ListNode *del = head;
            head = head->next;
            delete del;
        }

        if (!head) {
            return nullptr;
        }

        ListNode *prev = head;
        ListNode *thisOne = head->next;
        
        while (thisOne) {
            if (thisOne->val == val) {
                cout << "DELETED" << endl;
                prev->next = thisOne->next;
                delete thisOne;
                thisOne = prev->next;
                continue;      
            }

            prev = thisOne;
            thisOne = thisOne->next;
        }

        return head;
    }
};

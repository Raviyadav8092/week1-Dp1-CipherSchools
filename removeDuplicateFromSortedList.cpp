
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        head->next = deleteDuplicates(head->next);
        if(head->val == head->next->val) return head->next;
        return head;
    }
};
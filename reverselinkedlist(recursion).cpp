
class Solution {
public:
    ListNode* reverseListRecursively(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *newHead = reverseListRecursively(head->next);
        head->next->next = head;
        head->next= NULL;
        return newHead;
    }  
};
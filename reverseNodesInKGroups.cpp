
class Solution {
public:
    int counter(ListNode* head){
        if(!head) return 0;
        return 1 + counter(head->next);
    } 

    ListNode* reverseKGroup(ListNode* head, int k) {
        int cnt= 0;
        // if(!head || !head->next)return head;
        if(!head) return head;
        // if(counter(head) < k) return head;
        ListNode *curr= head,*prev = NULL,*next = NULL;
        while(curr && cnt<k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }
        if(next) head->next = reverseKGroup(next,k);
        return prev;
    }
};
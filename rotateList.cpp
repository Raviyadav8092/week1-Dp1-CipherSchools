
typedef ListNode Node;
class Solution {
public:
    int count(Node *head){
        if(!head) return 0;
        return 1 + count(head->next);
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(!head ) return head;
        Node * slow = head;
        Node * fast = head;
        int cnt = count(head);
        if(cnt == 1) return head;
        k %=cnt;
        if(k==0) return head;
        while(k--) fast= fast->next;
        while(fast->next) {slow = slow->next;fast = fast->next;}
        Node * head2 = slow->next;
        fast->next = head;
        slow->next = NULL;
        return head2;
    }
};
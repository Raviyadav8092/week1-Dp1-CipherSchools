
typedef ListNode Node;
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry =0 ;
        Node *head = new Node(-1);
        Node *tail = head;
        while(l1 || l2 || carry){
            int sum =0 ;
            if(l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum/10;
            tail->next = new Node(sum%10);
            tail = tail->next;
        }
        return head->next;
    }
};

typedef ListNode Node;
class Solution {
public:
    int count(Node * head){
        if(!head) return 0;
        return 1 + count(head->next);
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = count(headA);
        int len2 = count(headB);
        int diff = abs(len1 - len2);
        if(len1 > len2){
            for(int i = 1;i<=diff;i++) headA=headA->next;
        }
        else{
            for(int i=1;i<=diff;i++) headB=headB->next;
        }
        while(headA && headB && headA != headB) {
            headA= headA->next;
            headB=headB->next;
        }
        return headA;
    }
};
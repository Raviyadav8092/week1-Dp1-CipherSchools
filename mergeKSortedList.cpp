
class Solution {
public:

    ListNode* merge(ListNode * head1,ListNode * head2){
       if(!head1) return head2;
       if(!head2) return head1;
       ListNode *head,*tail,*temp = new ListNode(0);
       head = tail = temp;
       while(head1 && head2){
           if(head1->val <= head2->val){
               tail->next = head1;
               tail = tail->next;
               head1=head1->next;
           }
           else{
               tail->next = head2;
               tail = tail->next;
               head2=head2->next;
           }
       }
       if(head1){
           tail ->next = head1;
       }
       if(head2){
           tail->next = head2;
       }
       return head->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        else if(lists.size() == 1) return lists[0];
        else{
            int last = lists.size()-1;
            while(last>0){
            int i = 0,j = last;
            while(i<j){
                lists[i]= merge(lists[i],lists[j]);
                i++;j--;
            }
            if(i>=j) last = j;
            }
            return lists[0];
        }
    }
};
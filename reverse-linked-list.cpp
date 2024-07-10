    ListNode* reverseList(ListNode* head) 
    {
        ListNode * prev=NULL;
        ListNode * curr=head;
        ListNode * next=head;
        while(next)
        {
            next=next->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head=prev;
        return head;
    }

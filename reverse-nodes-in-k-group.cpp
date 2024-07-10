    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        int total=0;
        ListNode * ptr=head;
        while(ptr)
        {   
            total++;
            ptr=ptr->next;
        }
        int stop = k*(total/k);
        ListNode * curr=head;
        ListNode * next=head;
        ListNode * temp=NULL;
        bool flag=true;
        ListNode * prev=NULL;
        ListNode * lastNode=NULL;
        int c=0;
        while(next)
        {
            if(c==stop)
            {
                lastNode->next=next;
                break;
            }
            int count=k;
            temp=curr;
            while(count and next)
            {
                next=next->next;
                curr->next=prev;
                prev=curr;
                curr=next;
                count--;
                c++;
            }
            if(flag)
            {
                head=prev;
                flag=false;
            }
            if(lastNode) lastNode->next=prev;
            lastNode=temp;
            prev=NULL;
        }
        return head;
    }

    #define node ListNode
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(!head) return head;
        node * p = head;
        node * temp=NULL;
        int count=0;
        while(p)
        {
            temp=p;
            p=p->next;
            count++;
        }    
        temp->next=head;
        k%=count;
        count-=k;
        p = head;
        temp=NULL;
        while(count--)
        {
            temp=p;
            p=p->next;
        }
        temp->next=NULL;
        head=p;
        return head;
    }

    #define node ListNode
    ListNode* deleteDuplicates(ListNode* head) 
    {
        node * p = head;
        node * temp = NULL;
        node * prev=NULL;
        bool found=false;
        while(p and p->next and p->val==p->next->val)
        {
            while(p and p->next and p->val==p->next->val)
            {
                found=true;
                p=p->next;
            }
            if(found) p=p->next;
        }
        head=p;
        while(p)
        {
            prev=temp;
            temp=p;
            int val = p->val;
            p=p->next;
            bool flag=false;
            while(p and p->val==val) 
            {
                flag=true;
                p=p->next;
            }
            if(flag and prev) 
            {
                temp=prev;
                prev->next=p;
            }
        }
        return head;
    }

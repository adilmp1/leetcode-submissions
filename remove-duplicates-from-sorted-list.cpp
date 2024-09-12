    #define node ListNode
    ListNode* deleteDuplicates(ListNode* head) 
    {
        node * p = head;
        node * temp = NULL;
        while(p)
        {
            temp=p;
            int val = p->val;
            p=p->next;
            while(p and p->val==val) p=p->next;
            temp->next=p;
        }
        return head;
    }

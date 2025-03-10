    #define node ListNode
    int count(node * p)
    {
        int ans=0;
        while(p) 
        {
            p=p->next;
            ans++;
        }
        return ans;
    }
    ListNode* swapNodes(ListNode* head, int k) 
    {
        k--;
        int n = count(head);
        node * p = head;
        int left = k;
        int right = n-k-1;

        node * &first = head;
        node * &last = head;

        int it=0, v1=0, v2=0;
        while(p)
        {
            if(it==left) v1=p->val;
            if(it==right) v2=p->val;
            p=p->next;
            it++;
        }
        p=head;
        it=0;
        while(p)
        {
            if(it==left) p->val=v2;;
            if(it==right) p->val=v1;
            p=p->next;
            it++;
        }
        return head;
    }

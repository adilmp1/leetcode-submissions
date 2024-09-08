    #define node ListNode
    vector<ListNode*> splitListToParts(ListNode* head, int k) 
    {
        node *p = head;
        int count=0;
        while(p)
        {
            count++;
            p=p->next;
        }
        int groupSize = count/k;
        int pending = count-groupSize*k;
        if(count<k)
        {
            groupSize=1;
            pending=0;
        }
        vector<ListNode*> ans;
        p=head;
        while(p)
        {
            int stop=groupSize;
            if(pending) stop++;
            if(pending) pending--;
            node * start = p;
            stop--;
            while(stop-- and p)
            {
                p=p->next;
            }
            node * temp = NULL;
            if(p) temp = p->next;
            if(p) p->next=NULL;
            ans.push_back(start);
            p=temp;
        }
        while(ans.size()!=k)
        {
            ans.push_back(NULL);
        }

        return ans;
    }

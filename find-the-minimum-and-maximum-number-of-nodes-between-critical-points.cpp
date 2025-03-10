    #define node ListNode
    bool isCritical(node * a, node *b, node *c)
    {
        if(a and b and c)
        {
            int v1 = a->val;   
            int v2 = b->val;   
            int v3 = c->val;   

            bool b1 = (v2>v1 and v2>v3);
            bool b2 = (v2<v1 and v2<v3);
            return (b1 or b2);
        }
        return false;
    }
    vector<int> nodesBetweenCriticalPoints(ListNode* head) 
    {
        int maxi=-1;
        int mini=INT_MAX;
        node * p1 = head;
        node * temp = nullptr;
        int add=0;
        int first=-1;
        int last=-1;
        int curr=0;
        while(p1)
        {
            bool flag = isCritical(temp,p1,p1->next);
            if(flag)
            {
                if(first==-1)
                {
                    first=curr;
                }
                if(last!=-1)
                {
                    mini = min(mini,curr-last);
                }
                last=curr;
            }
            temp=p1;
            p1=p1->next;
            curr++;
        }
        if(first!=-1 and last!=-1 and first!=last)
        {
            maxi = last-first;
        }
        if(mini==INT_MAX) mini=-1;
        return {mini,maxi};
    }

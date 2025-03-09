    #define node ListNode
    int count(node * p)
    {
        int ans=0;
        while(p) 
        {
            ans++;
            p=p->next;
        }
        return ans;
    }
    int pairSum(ListNode* head) 
    {
        stack<int> s;
        int ans=0;
        node * p = head;
        int size = count(head);
        for(int i=0;i<size/2;i++)
        {
            s.push(p->val);
            p=p->next;
        }    
        while(p)
        {
            ans = max(ans,p->val+s.top());
            s.pop();
            p=p->next;
        }
        return ans;
    }

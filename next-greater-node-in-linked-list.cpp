    #define node ListNode
    vector<int> nextLargerNodes(ListNode* head) 
    {
        vector<int> a;
        node * p = head;
        while(p)
        {
            a.push_back(p->val);
            p=p->next;
        }
        int n = a.size();
        vector<int> ans(n,0);
        stack<int> s;
        s.push(0);
        for(int i=1;i<n;i++)
        {
            while(!s.empty() and a[i]>a[s.top()])
            {
                ans[s.top()]=a[i];
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }

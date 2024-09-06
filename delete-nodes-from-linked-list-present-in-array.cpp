    #define node ListNode
    ListNode* modifiedList(vector<int>& a, ListNode* head) 
    {
        unordered_map<int,int> mp;
        for(auto i:a) mp[i]=1;
        node * p = head;
        node * prev=NULL;
        while(p)
        {
            if(mp.count(p->val))
            {   
                if(p==head)
                {
                    head=head->next;
                    prev=NULL;
                    p=head;
                    continue;
                }
                else if(p->next==NULL)
                {
                    if(prev) prev->next=NULL;
                    if(!prev) return NULL;
                    return head;
                }
                else
                {
                    prev->next=p->next;
                    p=p->next;
                    continue;
                }
            }
            prev=p;
            p=p->next;
        }
        return head;
    }

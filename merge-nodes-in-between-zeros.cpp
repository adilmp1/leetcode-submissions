    #define node ListNode
    ListNode* mergeNodes(ListNode* head) 
    {
        node * ptr = head->next;
        node * p1 = head;
        node * ans = head;
        int sum=0;
        node * temp = nullptr;
        while(ptr)
        {
            if(!ptr->val)
            {
                p1->val = sum;
                temp=p1;
                p1=p1->next;
                sum=0;
            }
            sum+=ptr->val;
            ptr=ptr->next;
        }
        if(temp) temp->next = nullptr;
        return ans;
    }

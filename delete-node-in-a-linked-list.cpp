    #define node ListNode
    void deleteNode(ListNode* p1) 
    {
        node * temp = nullptr;
        while(p1->next)
        {
            temp=p1;
            p1->val = p1->next->val;
            p1=p1->next;
        }
        temp->next=nullptr;
    }

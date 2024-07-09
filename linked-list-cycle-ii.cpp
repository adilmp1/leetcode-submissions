    ListNode *detectCycle(ListNode *head) 
    {
        if(head==nullptr) return nullptr;
        ListNode * slow = head;
        ListNode * fast = head;
        do 
        {
            if(slow->next) slow=slow->next;
            else return nullptr;
            if(fast->next and fast->next->next) fast=fast->next->next;
            else return nullptr;
        }
        while( slow!=fast);
        slow=head;
        while(slow!=fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }

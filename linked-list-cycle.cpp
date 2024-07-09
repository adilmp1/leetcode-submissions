    bool hasCycle(ListNode *head) 
    {
        if(head==nullptr) return false;
        ListNode * slow = head;
        ListNode * fast = head;
        do 
        {
            if(slow->next) slow=slow->next;
            else return false;
            if(fast->next and fast->next->next) fast=fast->next->next;
            else return false;
        }
        while(slow!=fast);
        return true;
    }

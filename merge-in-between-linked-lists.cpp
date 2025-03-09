    #define node ListNode
    ListNode* mergeInBetween(ListNode* head1, int a, int b, ListNode* head2) 
    {
        node * p1 = head1;
        node * ans = p1;
        int c1=0;
        while(p1 and c1!=a-1)
        {
            p1=p1->next;
            c1++;
        }
        int c2=0;
        int k = b-a+1;
        node * p2 = p1;
        while(p2 and c2!=k+1)
        {
            p2=p2->next;
            c2++;
        }
        p1->next = head2;
        while(p1->next) p1=p1->next;
        p1->next = p2;
        return ans;
    }

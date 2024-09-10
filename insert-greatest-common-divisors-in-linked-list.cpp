    #define node ListNode
    int gcd(int a,int b)
    {
        return (a%b==0)?b:gcd(b,a%b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) 
    {
        node * p = head;
        while(p)
        {
            if(!(p->next)) return head;
            int v1 = p->val;
            int v2 = p->next->val;
            int val = gcd(v1,v2);
            node * temp = p->next;
            node * newNode = new node(val);
            p->next = newNode;
            newNode->next=temp;
            p=temp;
        }   
        return head; 
    }

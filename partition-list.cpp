    // real solution
    #define node ListNode
    ListNode* partition(ListNode* head, int x) {
        node * list1 = new node(0);
        node * list2 = new node(0);

        node * l1 = list1;
        node * l2 = list2;

        node * p =head;
        while(p)
        {
            if(p->val<x)
            {
                l1->next=p;
                l1=l1->next;
            }
            else
            {
                l2->next=p;
                l2=l2->next;
            }
            p=p->next;
        }
        l1->next=list2->next;
        l2->next=NULL;
        return list1->next;
    }

    // udayip solution
    #define node ListNode
    ListNode* partition(ListNode* head, int x) {
        vector<int> a;
        node* p = head;
        while (p) {
            a.push_back(p->val);
            p = p->next;
        }
        p = head;
        for (auto i : a) {
            if (i < x) {
                p->val = i;
                p = p->next;
            }
        }
        for (auto i : a) {
            if (i >= x) {
                p->val = i;
                p = p->next;
            }
        }
        return head;
    }

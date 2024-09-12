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

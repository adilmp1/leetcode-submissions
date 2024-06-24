    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        using Pair = pair<int, ListNode*>;
        auto compare = [](const Pair& a, const Pair& b) {
            return a.first > b.first;
        };
        priority_queue<Pair, vector<Pair>, decltype(compare)> pq(compare);
        
        ListNode * head = NULL;
            for(ListNode* node:lists)
            {
                if(node)
                {
                    pq.push({node->val,node});
                }
            }

        ListNode * ptr = NULL;
        while(!pq.empty())
        {
            int val = pq.top().first;
            ListNode * temp = pq.top().second;
            if(head)
            {
                ptr->next = temp;
                ptr=ptr->next;
            }
            else
            {
                head=temp;
                ptr=head;
            }
            if(temp->next) pq.push({temp->next->val,temp->next});
            pq.pop();
        }
        return head;    
    }

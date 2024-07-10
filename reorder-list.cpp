    ListNode * reverse(ListNode * &head)
    {
        ListNode * prev=NULL;
        ListNode * curr=head;
        ListNode * next=head;
        while(next)
        {
            next=next->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head=prev;
        return head;
    }
    pair<ListNode *,ListNode *> middle(ListNode *&head)
    {
        ListNode * mid=head;
        ListNode * fast=head;
        ListNode * prev=NULL;
        while(fast)
        {
            if(!(mid->next)) 
            {
                prev->next=NULL;
                return {head,mid}; 
            }
            prev=mid;
            mid=mid->next;
            if(!(fast->next and fast->next->next)) 
            {
                prev->next=NULL;
                return {head,mid};
            }
            fast=fast->next->next;
        }
        head->next=NULL;
        return {head,mid};
    } 
    ListNode * reorderListHelper(ListNode * &head,ListNode * &mid)
    {
        if(!(head or mid)) return NULL;
        if(!head) return mid;
        if(!mid) return head;
        ListNode *v1 = head->next;
        ListNode *v2 = mid->next;
        head->next=mid;
        mid->next=reorderListHelper(v1,v2);
        return head;
    }
    void reorderList(ListNode *&head) 
    {
        if(head->next==NULL) return;
        if(head->next->next==NULL) return;
        pair<ListNode*,ListNode*> pr = middle(head);
        head = pr.first;
        ListNode * mid=pr.second;
        mid=reverse(mid);
        head=reorderListHelper(head,mid);
    }

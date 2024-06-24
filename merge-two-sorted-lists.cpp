    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        if(!list1 and !list2) return NULL;
        else if (!list1) return list2;
        else if (!list2) return list1;
        ListNode* head = NULL;
        if(list1->val < list2->val)
        {
            head=list1;
            list1=list1->next;
        }
        else
        {
            head=list2;
            list2=list2->next;
        }
        ListNode * ptr=head;
        while(list1 and list2)
        {
            if(list1->val < list2->val)
            {
                ptr->next=list1;
                list1=list1->next;
            }
            else
            {
                ptr->next=list2;
                list2=list2->next;
            }
            ptr=ptr->next;
        }
        while(list1)
        {
            ptr->next=list1;
            list1=list1->next;
            ptr=ptr->next;
        }
        while(list2)
        {
            ptr->next=list2;
            list2=list2->next;
            ptr=ptr->next;
        }
        return head;
    }

#define node ListNode

ListNode *reverseList(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *next = head;
    while (next)
    {
        next = next->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}

ListNode *removeNodes(ListNode *head)
{
    head = reverseList(head);

    int maxi = INT_MIN;

    node * newHead = new node(0);
    node * newNode = newHead;
    node * p = head;

    while(p)
    {
        if(maxi <= p->val)
        {
            newNode->next = p;
            newNode = newNode->next;
            maxi=p->val;
        }
        p=p->next;
    }
    newNode->next = nullptr;
    newHead=newHead->next;
    return reverseList(newHead);
}

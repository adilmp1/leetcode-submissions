/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    #define node ListNode
    int count(node * p)
    {
        int ans=0;
        while(p) 
        {
            p=p->next;
            ans++;
        }
        return ans;
    }
    node * ptr = nullptr;
    Solution(ListNode* head) {
        ptr = head;
    }
    
    int getRandom() {
        int size = count(ptr);
        int idx = rand()%size;
        node * curr = ptr;
        while(idx--)
        {
            curr=curr->next;
        }
        return curr->val;
    }
};


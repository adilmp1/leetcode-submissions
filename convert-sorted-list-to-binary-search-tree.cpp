    #define lNode ListNode
    #define tNode TreeNode
    tNode * buildTree(vector<int>& a,int left,int right)
    {
        if(left>right) return nullptr;
        int mid = (left+right) / 2;
        tNode * root = new tNode(a[mid]);
        root->left = buildTree(a,left,mid-1);
        root->right = buildTree(a,mid+1,right);
        return root;

    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return nullptr;
        lNode * p = head;
        vector<int> sorted_arr;
        while(p)
        {
            sorted_arr.push_back(p->val);
            p=p->next;
        }
        return buildTree(sorted_arr,0,sorted_arr.size()-1);
    }

    #define Node TreeNode
    Node * buildTree(vector<int>& a,int left,int right)
    {
        if(left>right) return nullptr;
        int maxi = INT_MIN;
        int idx = -1;
        for(int i=left;i<=right;i++)
        {
            if(maxi < a[i])
            {
                maxi=a[i];
                idx=i;
            }
        }
        Node * root = new Node(maxi);
        root->left = buildTree(a,left,idx-1);
        root->right = buildTree(a,idx+1,right);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return buildTree(nums,0,nums.size()-1);
    }

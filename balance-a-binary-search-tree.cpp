    TreeNode* sortedArrayToBSTHelper(vector<int>& a,int i,int j)
    {   
        if(i>j) return nullptr;
        int mid = (i+j)/2;
        int val = a[mid];
        TreeNode* root = new TreeNode(val);
        root->left = sortedArrayToBSTHelper(a,i,mid-1);
        root->right = sortedArrayToBSTHelper(a,mid+1,j);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        return sortedArrayToBSTHelper(nums,0,nums.size()-1);
    }
    vector<int> a;
    void inOrder(TreeNode* root)
    {
        if(!root) return;
        inOrder(root->left);
        a.push_back(root->val);
        inOrder(root->right);
    }
    TreeNode* balanceBST(TreeNode* root) {
        
        inOrder(root);
        return sortedArrayToBST(a);
    }

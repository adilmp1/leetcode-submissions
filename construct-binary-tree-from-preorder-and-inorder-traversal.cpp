    TreeNode * buildTreeHelper(vector<int>& preorder,int preStart,int preEnd,vector<int>& inorder,int inStart,int inEnd,unordered_map<int,int>& mp)
    {
        if(preStart>preEnd or inStart>inEnd) return NULL;

        TreeNode * root = new TreeNode(preorder[preStart]);
        int inPos = mp[root->val];
        int numLeft = inPos-inStart;
        root->left=buildTreeHelper(preorder,preStart+1,preStart+numLeft,inorder,inStart,inPos-1,mp);
        root->right=buildTreeHelper(preorder,preStart+numLeft+1,preEnd,inorder,inPos+1,inEnd,mp);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        TreeNode * root = buildTreeHelper(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
        return root;
    }

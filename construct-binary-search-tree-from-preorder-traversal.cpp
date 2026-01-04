    #define Node TreeNode
    unordered_map<int,int> index;
    Node * buildTree(vector<int>& preorder,int preStart,int preEnd,vector<int>& inorder,int inStart,int inEnd)
    {
        if(preStart>preEnd or inStart>inEnd) return nullptr;
        Node * root = new Node(preorder[preStart]);
        int leftSize = index[root->val]-inStart;
        root->left = buildTree(preorder,preStart+1,preStart+leftSize,inorder,inStart,inStart+leftSize-1);
        root->right = buildTree(preorder,preStart+leftSize+1,preEnd,inorder,inStart+leftSize+1,inEnd);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(),inorder.end());
        for(int i=0;i<inorder.size();i++) index[inorder[i]]=i;
        return buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }

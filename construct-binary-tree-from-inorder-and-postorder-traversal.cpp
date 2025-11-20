    unordered_map<int,int> mp;
    #define Node TreeNode
    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder,int inStart,int inEnd,int postStart,int postEnd)
    {   
        if(inStart>inEnd or postStart>postEnd) return nullptr;
        int value = postorder[postEnd];
        Node * root = new Node(value);
        int inPos = mp[value]; 
        int leftSize = inPos-inStart;
        root->left = buildTreeHelper(inorder,postorder,inStart,inPos-1,postStart,postStart+leftSize-1);
        root->right = buildTreeHelper(inorder,postorder,inPos+1,inEnd,postStart+leftSize,postEnd-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++) mp[inorder[i]]=i;
        return buildTreeHelper(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
    }

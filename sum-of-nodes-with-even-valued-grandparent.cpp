    #define Node TreeNode
    int sumEvenGrandparent(TreeNode* root,Node * grandParent=nullptr,Node * parent = nullptr) {
        if(!root) return 0;
        int ans=0;
        if(grandParent and (grandParent->val%2)==0) ans+=root->val;
        ans+=sumEvenGrandparent(root->left,parent,root);
        ans+=sumEvenGrandparent(root->right,parent,root);
        return ans;
    }

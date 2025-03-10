    #define node TreeNode
    void flatten(TreeNode* root) {
        node * curr = root;

        while(curr)
        {
            if(curr->left)
            {
                node * temp = curr->left;
                while(temp->right) temp=temp->right;
                temp->right = curr->right;
                curr->right = curr->left;
                curr->left= nullptr; 
            }
            curr=curr->right;
        }
    }

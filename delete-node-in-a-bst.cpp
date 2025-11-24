    #define Node TreeNode

    int inOrderSuccessor(Node * root) 
    { 
        int ans=0; 
        Node * successor = nullptr; 
        while(root) 
        { 
            ans=root->val; 
            successor = root; 
            root=root->left; 
        }
        return ans; 
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        if(root->val < key) root->right = deleteNode(root->right,key);
        else if(root->val > key) root->left = deleteNode(root->left,key);
        else
        {
            if(!root->left and !root->right)
            {
                delete root;
                return nullptr;
            }
            else if(!root->left)
            {
                Node * temp = root->right;
                delete root;
                return temp;
            }
            else if(!root->right)
            {
                Node * temp = root->left;
                delete root;
                return temp;
            }
            else
            {   
                Node * succ = root->right;
                while(succ->left) succ=succ->left;
                root->val = succ->val;
                root->right = deleteNode(root->right,succ->val);
            }
        }
        return root;
    }

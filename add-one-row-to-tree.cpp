    #define Node TreeNode
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(!root and depth==2) return new Node(val);
        queue<Node*> q;
        q.push(root);
        if(depth==1)
        {
            Node * newRoot = new Node(val);
            newRoot->left = root;
            return newRoot;
        }
        int cd = 2;
        while(!q.empty())
        {
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                Node * node = q.front();
                if(cd==depth)
                {
                    Node * left = new Node(val);
                    Node * right = new Node(val);
                    left->left = node->left;
                    right->right = node->right;
                    node->left = left;
                    node->right = right;
                }
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            cd++;
        } 
        return root;
    }

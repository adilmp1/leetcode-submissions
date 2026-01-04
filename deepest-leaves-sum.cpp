    #define Node TreeNode
    int deepestLeavesSum(TreeNode* root) {
        int ans=0;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            ans=0;
            for(int i=0;i<size;i++)
            {
                Node * node = q.front();
                ans+=node->val;
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return ans;
    }

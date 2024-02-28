    int findBottomLeftValue(TreeNode* root) 
    {
        queue<TreeNode*> q;
        int count=0;
        q.push(root);
        int ans=0;
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode * node = q.front();q.pop();
                if(i==0) ans=node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return ans;
    }

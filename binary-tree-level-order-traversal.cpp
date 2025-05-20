    #define node TreeNode
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<node*> q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            vector<int> temp;
            for(int i=0;i<n;i++)
            {
                node * d = q.front();
                temp.push_back(d->val);
                if(d->left) q.push(d->left);
                if(d->right) q.push(d->right);
                q.pop();
            }
            ans.push_back(temp);
        }
        return ans;
    }

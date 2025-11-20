    #define Node TreeNode
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return {};
        queue<Node*> q;
        q.push(root);
        vector<vector<int>> ans;
        while(!q.empty())
        {
            int size = q.size();
            vector<int> temp;
            for(int i=0;i<size;i++)
            {
                Node * node = q.front();
                temp.push_back(node->val);
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(temp);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

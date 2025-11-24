    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            vector<int> temp;
            for(int i=0;i<size;i++)
            {
                Node * node = q.front();
                q.pop();
                temp.push_back(node->val);
                for(auto child:node->children) q.push(child);
            }
            ans.push_back(temp);
        }
        return ans;
    }

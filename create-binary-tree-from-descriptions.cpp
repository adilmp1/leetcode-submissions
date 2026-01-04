    #define Node TreeNode
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) 
    {
        unordered_map<int,Node*> mp; 
        unordered_set<Node*> children;
        for(auto& desc:descriptions)
        {
            Node * node1 = nullptr;
            Node * node2 = nullptr;

            if (mp.find(desc[0]) != mp.end()) node1 = mp[desc[0]];
            else 
            {
                node1 = new Node(desc[0]);
                mp[desc[0]]=node1;
            }
            if(mp.find(desc[1])!=mp.end()) node2 = mp[desc[1]];
            else 
            {
                node2 = new Node(desc[1]);
                mp[desc[1]]=node2;
            }
            if(desc[2]==1) node1->left = node2;
            else node1->right = node2;
            children.insert(node2);
        }
        for(auto & pair:mp) if(children.find(pair.second)==children.end()) return pair.second;
        return nullptr;
    }

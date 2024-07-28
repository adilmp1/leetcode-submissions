    unordered_map<Node*,Node*> mp;
    Node * cloneGraph(Node * node)
    {
        if(!node) return NULL;
        if(mp.find(node)!=mp.end()) return mp[node];
        Node * root=new Node(node->val);
        mp[node]=root;
        for(auto i:node->neighbors)
        {
            Node * next = cloneGraph(i);
            if(next) root->neighbors.push_back(next);
        }
        return root;
    }

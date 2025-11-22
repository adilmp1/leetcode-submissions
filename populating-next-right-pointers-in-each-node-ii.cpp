    Node* connect(Node* root) {
        if(!root) return nullptr;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            Node * prev = nullptr;
            for(int i=0;i<size;i++)
            {
                Node * node = q.front();
                if(prev) prev->next = node; 
                prev = node;
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return root;
    }

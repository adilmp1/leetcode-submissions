    Node* connect(Node* root) 
    {
        if(!root) return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                Node * p = q.front();
                q.pop();
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
                if(i<size-1) p->next = q.front();
            }
        }
        return root;
    }

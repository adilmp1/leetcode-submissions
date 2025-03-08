    #define node TreeNode
    TreeNode* reverseOddLevels(TreeNode* root) 
    {
            queue<node*> q;
            q.push(root);
            int loop=0;
            while(!q.empty())
            {
                int size = q.size();
                queue<node*> q1;
                stack<int> s;
                for(int i=0;i<size;i++)
                {
                    node * curr = q.front();
                    if((loop&1)==1)
                    {
                        q1.push(curr);
                        s.push(curr->val);
                    }   
                    q.pop();
                    cout<<curr->val<<" ";
                    if(curr->left) q.push(curr->left);
                    if(curr->right) q.push(curr->right);
                }
                while(!q1.empty())
                {
                    node*& curr = q1.front();
                    curr->val = s.top();
                    s.pop();
                    q1.pop();
                }
                cout<<endl;
                loop++;
            } 
            return root;
    }

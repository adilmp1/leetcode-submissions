    bool isEvenOddTree(TreeNode* root) 
    {
        queue<TreeNode*> q;
        q.push(root);
        int lvl=0;
        while(!q.empty())
        {
            int n = q.size();
            bool flag=true;
            int val=-1;
            if(lvl%2==0)
            {
                for(int i=0;i<n;i++)
                {
                    TreeNode* node = q.front();q.pop();
                    if((node->val%2)==0)
                    {
                        flag=false;break;
                    }
                    else if(val==-1) 
                    {
                        val=node->val;
                    }
                    else
                    {
                        if(node->val <= val)
                        {
                            flag=false;
                            break;
                        }
                        val=node->val;
                    }
                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);
                }
            }   
            else
            {
                for(int i=0;i<n;i++)
                {
                    TreeNode* node = q.front();q.pop();
                    if((node->val%2)==1)
                    {
                        flag=false;break;
                    }
                    else if(val==-1) 
                    {
                        val=node->val;
                    }
                    else
                    {
                        if(node->val>=val)
                        {
                            flag=false;
                            break;
                        }
                        val=node->val;
                    }
                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);
                }
            }
            if(!flag) return flag;
            lvl++;
        }
        return true;
    }

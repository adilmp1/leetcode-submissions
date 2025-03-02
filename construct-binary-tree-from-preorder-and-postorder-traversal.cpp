    #define node TreeNode
    unordered_map<int,int> mp;
    node * helper(vector<int>& pre,vector<int>& post,int preStart,int preEnd,int postStart,int postEnd)
    {
        if(preStart>preEnd or postStart>postEnd) return nullptr;
        node * root = new node(pre[preStart]);
        if(preStart==preEnd) return root;
        int val = mp[pre[preStart+1]];
        int size = val-postStart+1;
        root->left = helper(pre,post,preStart+1,preStart+size,postStart,val);
        root->right = helper(pre,post,preStart+size+1,preEnd,val+1,postEnd-1);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) 
    {
        int n = pre.size();
        for(int i=0;i<n;i++)
        {
            mp[post[i]]=i;
        }
        return helper(pre,post,0,n-1,0,n-1);
    }

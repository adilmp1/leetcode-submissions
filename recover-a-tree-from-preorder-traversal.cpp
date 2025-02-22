    #define node TreeNode
    string s;
    int idx=0;
    int level=0;
    void helper(node * parent, int lvl)
    {
        while(idx<s.size() and lvl==level)
        {
            int num = 0;
            while(idx<s.size() and isdigit(s[idx]))
            {
                num*=10;
                num+=s[idx]-'0';
                idx++;
            }
            node * temp = new node(num);
            if(!parent->left) parent->left = temp;
            else parent->right = temp;
            level=0;
            while(idx<s.size() and s[idx]=='-') 
            {
                idx++;
                level++;
            }
            helper(temp,lvl+1);
        }
    }
    TreeNode* recoverFromPreorder(string traversal) {
        s = traversal;
        node * parent = new node(-1);
        helper(parent,0);
        return parent->left;
    }

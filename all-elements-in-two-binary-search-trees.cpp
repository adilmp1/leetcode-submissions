    #define Node TreeNode
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
        vector<int> ans;
        stack<Node*> s1, s2;
        Node * curr1 = root1;
        Node * curr2 = root2;
        while((!s1.empty() or curr1) or (!s2.empty() or curr2) )
        {
            while(curr1)
            {
                if(!s1.empty() and s1.top()==curr1) break;
                s1.push(curr1);
                curr1=curr1->left;
            }
            while(curr2)
            {
                if(!s2.empty() and s2.top()==curr2) break;
                s2.push(curr2);
                curr2=curr2->left;
            }
            if(!s1.empty()) curr1 = s1.top();
            if(!s2.empty()) curr2 = s2.top();
            int v1 = curr1 ? curr1->val: INT_MAX;
            int v2 = curr2 ? curr2->val: INT_MAX;
            if(v1<v2)
            {
                ans.push_back(v1);
                s1.pop();
                curr1=curr1->right;
            }
            else if(v1!=INT_MAX or v2!=INT_MAX)
            {
                ans.push_back(v2);
                s2.pop();
                curr2=curr2->right;
            }
        }
        return ans;
    }

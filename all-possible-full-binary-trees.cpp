    #define Node TreeNode
    unordered_map<int, vector<Node*>> dp;
    vector<TreeNode*> allPossibleFBT(int n) {
        if(dp.count(n)) return dp[n];
        if(n%2==0) return {};
        if(n==1) return {new Node(0)};
        vector<Node*> ans;
        for(int left=1;left<n;left+=2)
        {
            vector<Node*> leftSubTrees = allPossibleFBT(left);
            vector<Node*> rightSubTrees = allPossibleFBT(n-left-1);
            for(auto leftNode:leftSubTrees)
            {
                for(auto rightNode:rightSubTrees)
                {
                    Node * root = new Node(0);
                    root->left = leftNode;
                    root->right = rightNode;
                    ans.push_back(root);
                }
            }
        }
        return dp[n]=ans;
    }

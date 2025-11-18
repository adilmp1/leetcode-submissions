    #define Node TreeNode

    vector<Node*> generateTreesHelper(int left,int right)
    {
        vector<Node*> ans;
        if(left>right) return {nullptr};

        for(int i=left;i<=right;i++)
        {

            vector<Node*> leftSubTrees = generateTreesHelper(left,i-1);
            vector<Node*> rightSubTrees = generateTreesHelper(i+1,right);

            for(auto leftNode:leftSubTrees)
            {
                for(auto rightNode:rightSubTrees)
                {
                    Node * root = new Node(i);
                    root->left = leftNode;
                    root->right = rightNode;
                    ans.push_back(root);
                }
            }

        }

        return ans;

    }

    vector<TreeNode*> generateTrees(int n) {
        return generateTreesHelper(1,n);
    }

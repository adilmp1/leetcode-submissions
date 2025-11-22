    #define Node TreeNode
    vector<vector<int>> ans;
    void pathSumHelper(Node * root,int target, vector<int> temp)
    {
        if(!root) return;
        target-=root->val;
        temp.push_back(root->val);
        if(!target and !root->left and !root->right)
        {
            ans.push_back(temp);
            return;
        }
        pathSumHelper(root->left,target,temp);
        pathSumHelper(root->right,target,temp);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<int> temp;
        pathSumHelper(root,target,temp);
        return ans;
    }

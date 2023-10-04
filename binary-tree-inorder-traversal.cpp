vector<int> inorderTraversal(TreeNode *root)
{
    if (root == NULL)
        return {};
    vector<int> ans;
    unordered_map<TreeNode *, int> mp;
    stack<TreeNode *> s;
    s.push(root);
    while (!s.empty())
    {
        TreeNode *node = s.top();
        if (node->left == NULL || mp.count(node->left))
        {
            s.pop();
            mp[node]++;
            ans.push_back(node->val);
        }
        if (node->left != NULL and mp.find(node->left) == mp.end())
        {
            s.push(node->left);
        }
        else if (node->right != NULL and mp.find(node->right) == mp.end())
        {
            s.push(node->right);
        }
    }
    mp.clear();
    return ans;
}

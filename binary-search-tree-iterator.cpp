class BSTIterator {
public: 
    #define Node TreeNode
    Node * curr = nullptr;
    stack<Node*> s;
    BSTIterator(TreeNode* root) {
        curr = root;
    }
    
    int next() {
        while(curr or !s.empty())
        {
            while(curr)
            {
                s.push(curr);
                curr=curr->left;
            }
            curr = s.top();
            s.pop();
            int ans = curr->val;
            curr=curr->right;
            return ans;
        }     
        return -1;
    }
    
    bool hasNext() {
        return (curr or !s.empty());
    }
};

bool ans=false;
bool helper(ListNode *head, TreeNode *root)
{
    if(!head) return true;
    if(!root) return false;
    if(root->val!=head->val) return false;  
    return (helper(head->next,root->left) or helper(head->next,root->right));
}
void isSubPathHelper(ListNode *head, TreeNode *root)
{
    if(!root) return;
    if(root->val==head->val) 
    {
        if(helper(head,root)) 
        {
            ans=true;   
            return;
        }
    }
    isSubPathHelper(head,root->left);
    isSubPathHelper(head,root->right);
}

bool isSubPath(ListNode *head, TreeNode *root)
{
    isSubPathHelper(head,root);
    return ans;
}

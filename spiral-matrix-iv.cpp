    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) 
    {
        vector<vector<int>> a(m,vector<int>(n,-1));
        int top = 0;
        int left=0;
        int right = n-1;
        int bottom=m-1;
        while(head and top<=bottom and left<=right)
        {
            for(int i=left;i<=right and head;i++)
            {
                a[top][i]=head->val;
                head=head->next;
            }
            top++;
            for(int i=top;i<=bottom and head;i++)
            {
                a[i][right]=head->val;
                head=head->next;
            }
            right--;
            for(int i=right;i>=left and head;i--)
            {
                a[bottom][i]=head->val;
                head=head->next;
            }
            bottom--;
            for(int i=bottom;i>=top and head;i--)
            {
                a[i][left]=head->val;
                head=head->next;
            }
            left++;
        }
        return a;
    }

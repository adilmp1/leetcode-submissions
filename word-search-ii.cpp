struct node
{
    char c;
    int ends;
    node *child[26];
    string word;
};

struct node *createNode(char c)
{
    node *newNode = new node;
    newNode->c = c;
    newNode->ends = 0;
    newNode->word = "";
    for (int i = 0; i < 26; i++)
    {
        newNode->child[i] = NULL;
    }
    return newNode;
}

node *root = createNode('/');

void insert(string s)
{
    node *curr = root;
    int i = 0;
    int index;
    while (s[i])
    {
        index = s[i] - 'a';
        if (curr->child[index] == NULL)
            curr->child[index] = createNode(s[i]);
        curr = curr->child[index];
        i++;
    }
    curr->ends++;
    curr->word = s;
}

void findWordsHelper(vector<vector<char>> &a, int x, int y, int m, int n, node *curr,vector<string>& ans)
{
    int index = a[x][y]-'a';

    if(a[x][y]=='$' or curr->child[index]==NULL)
    {
        return;
    }

    curr=curr->child[index];

    if(curr->ends>0)
    {
        ans.push_back(curr->word);
        curr->ends--;
    }

    char ch = a[x][y];
    a[x][y] = '$';
    if (x > 0)
        findWordsHelper(a, x - 1, y, m, n, curr,ans);
    if (x < m - 1)
        findWordsHelper(a, x + 1, y, m, n, curr,ans);
    if (y > 0)
        findWordsHelper(a, x, y - 1, m, n, curr,ans);
    if (y < n - 1)
        findWordsHelper(a, x, y + 1, m, n, curr,ans);
    a[x][y] = ch;
}

vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
{
    vector<string> ans;
    int m = board.size(), n = board[0].size();
    for (string i : words)
    {
        insert(i);
    }
    node *curr = root;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            findWordsHelper(board, i, j, m, n, curr,ans);
        }
    }
    return ans;
}

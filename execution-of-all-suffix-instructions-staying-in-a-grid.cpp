bool isValid(int x,int y,int n)
{
    return (x>=0 and y>=0 and x<n and y<n);
}

void move(char c,int &x,int &y)
{
    if(c=='R')
    {
        y++;
    } 
    else if(c=='L')
    {
        y--;
    }
    else if(c=='U')
    {
        x--;
    }
    else if(c=='D')
    {
        x++;
    }
    
}

int helper(int x,int y,int n,string s,int i)
{
    int ans = 0;
    while(i<s.size())
    {
        move(s[i],x,y);
        if(isValid(x,y,n)) ans++;
        else break;
        i++;
    }
    return ans;
}

vector<int> executeInstructions(int n, vector<int>& startPos, string s) 
{
    vector<int> ans;
    for(int i=0;i<s.size();i++)
    {
        int x = startPos[0];
        int y = startPos[1];
        int val = helper(x,y,n,s,i);
        ans.push_back(val);
    }
    return ans;
}

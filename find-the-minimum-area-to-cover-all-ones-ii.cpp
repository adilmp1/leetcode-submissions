int Top=-1;
int Bottom=-1;
int Left=-1;
int Right=-1;
int minimumArea(int lowX, int highX, int lowY, int highY, vector<vector<int>> &a,bool flag=false)
{
    bool found=false;
    int top = INT_MAX;
    int bottom = INT_MIN;
    int left = INT_MAX;
    int right = INT_MIN;
    for (int i = lowX; i <= highX; i++)
    {
        for (int j = lowY; j <= highY; j++)
        {
            if (a[i][j])
            {
                found=true;
                top = min(top, i);
                bottom = max(bottom, i);
                left = min(left, j);
                right = max(right, j);
            }
        }
    }
    if(!found) return INT_MAX;
    if(flag)
    {
        Top = top;
        Bottom = bottom;
        Left=left;
        Right = right;
    }
    int ans = (bottom - top + 1) * (right - left + 1);
    return ans;
}

int minimumSum(vector<vector<int>> &a)
{
    minimumArea(0,a.size()-1,0,a[0].size()-1,a,true);
    int ans = INT_MAX;
    int temp=0,val=0;
    for(int i=Top;i<Bottom-1;i++)
    {
        for(int j=i+1;j<Bottom;j++)
        {
            temp = 0;
            val = minimumArea(Top,i,Left,Right,a);
            if(temp!=INT_MAX and val!=INT_MAX) temp+=val;
            else if(val==INT_MAX) temp=INT_MAX;
            val = minimumArea(i+1,j,Left,Right,a);
            if(temp!=INT_MAX and val!=INT_MAX) temp+=val;
            else if(val==INT_MAX) temp=INT_MAX;
            val = minimumArea(j+1,Bottom,Left,Right,a);
            if(temp!=INT_MAX and val!=INT_MAX) temp+=val;
            else if(val==INT_MAX) temp=INT_MAX;

            ans = min(ans,temp);
        }
    }

    for(int i=Left;i<Right-1;i++)
    {
        for(int j=i+1;j<Right;j++)
        {
            temp = 0;
            val = minimumArea(Top,Bottom,Left,i,a);
            if(temp!=INT_MAX and val!=INT_MAX) temp+=val;
            else if(val==INT_MAX) temp=INT_MAX;
            val = minimumArea(Top,Bottom,i+1,j,a);
            if(temp!=INT_MAX and val!=INT_MAX) temp+=val;
            else if(val==INT_MAX) temp=INT_MAX;
            val = minimumArea(Top,Bottom,j+1,Right,a);
            if(temp!=INT_MAX and val!=INT_MAX) temp+=val;
            else if(val==INT_MAX) temp=INT_MAX;
            ans = min(ans,temp);
        }
    }

    for(int i=Top;i<Bottom;i++)
    {
        for(int j=Left;j<Right;j++)
        {
            temp = 0;
            val = minimumArea(Top,i,Left,Right,a);
            if(temp!=INT_MAX and val!=INT_MAX) temp+=val;
            else if(val==INT_MAX) temp=INT_MAX;
            val = minimumArea(i+1,Bottom,Left,j,a);
            if(temp!=INT_MAX and val!=INT_MAX) temp+=val;
            else if(val==INT_MAX) temp=INT_MAX;
            val = minimumArea(i+1,Bottom,j+1,Right,a);
            if(temp!=INT_MAX and val!=INT_MAX) temp+=val;
            else if(val==INT_MAX) temp=INT_MAX;
            ans = min(ans,temp);
            
            temp = 0;
            val = minimumArea(i+1,Bottom,Left,Right,a);
            if(temp!=INT_MAX and val!=INT_MAX) temp+=val;
            else if(val==INT_MAX) temp=INT_MAX;
            val = minimumArea(Top,i,Left,j,a);
            if(temp!=INT_MAX and val!=INT_MAX) temp+=val;
            else if(val==INT_MAX) temp=INT_MAX;
            val = minimumArea(Top,i,j+1,Right,a);
            if(temp!=INT_MAX and val!=INT_MAX) temp+=val;
            else if(val==INT_MAX) temp=INT_MAX;
            ans = min(ans,temp);

            temp = 0;
            val = minimumArea(Top,Bottom,Left,j,a);
            if(temp!=INT_MAX and val!=INT_MAX) temp+=val;
            else if(val==INT_MAX) temp=INT_MAX;
            val = minimumArea(Top,i,j+1,Right,a);
            if(temp!=INT_MAX and val!=INT_MAX) temp+=val;
            else if(val==INT_MAX) temp=INT_MAX;
            val = minimumArea(i+1,Bottom,j+1,Right,a);
            if(temp!=INT_MAX and val!=INT_MAX) temp+=val;
            else if(val==INT_MAX) temp=INT_MAX;
            ans = min(ans,temp);

            temp = 0;
            val = minimumArea(Top,Bottom,j+1,Right,a);
            if(temp!=INT_MAX and val!=INT_MAX) temp+=val;
            else if(val==INT_MAX) temp=INT_MAX;
            val = minimumArea(Top,i,Left,j,a);
            if(temp!=INT_MAX and val!=INT_MAX) temp+=val;
            else if(val==INT_MAX) temp=INT_MAX;
            val = minimumArea(i+1,Bottom,Left,j,a);
            if(temp!=INT_MAX and val!=INT_MAX) temp+=val;
            else if(val==INT_MAX) temp=INT_MAX;
            ans = min(ans,temp);
        }
    }
    return ans;
}

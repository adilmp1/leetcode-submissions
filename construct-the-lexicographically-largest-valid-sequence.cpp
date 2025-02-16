bool isOkay(int x,int y,vector<int>& ans)
{
    return(x>=0 and x<ans.size() and y>=0 and y<ans.size() and ans[x]==-1 and ans[y]==-1);
}

bool helper(vector<int>& ans,vector<bool>& done,int n)
{
    for(int i=0;i<ans.size();i++)
    {
        if(ans[i]==-1)
        {
            bool flag=true;
            for(int j=n;j>1;j--)
            {
                if(!done[j] and isOkay(i,i+j,ans))
                {
                    ans[i]=j;
                    ans[i+j]=j;
                    done[j]=true;
                    flag=false;
                    if(helper(ans,done,n))
                    {
                        continue;
                    }
                    else
                    {
                        ans[i]=-1;
                        ans[i+j]=-1;
                        done[j]=false;
                        flag=true;
                        continue;
                    }
                }
            }
            if(flag and !done[1]) 
            {
                ans[i]=1;
                done[1]=true;
                if(helper(ans,done,n))
                {
                    continue;
                }
                else
                {
                    ans[i]=-1;
                    done[1]=false;
                    flag=true;
                }
            }
        }   
        if(ans[i]==-1) return false;
    }
    return true;
}

vector<int> constructDistancedSequence(int n) {
    vector<int> ans(2*n-1,-1);
    vector<bool> done(n+1,false);
    helper(ans,done,n);
    return ans;
}

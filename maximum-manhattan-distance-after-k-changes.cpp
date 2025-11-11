int maxDistance(string s, int k)
{
    int countN = 0, countE = 0, countW = 0, countS = 0;
    int ans=0;
    int copy = k;

    /*

            N <-> S
            E <-> W
    
    */

    // case 1 changing N to S and E to W
    for (auto direction : s)
    {
        if(direction=='W') countW++;
        if(direction=='S') countS++;
        if(direction=='N' or direction=='E')
        {
            if(k)
            {
                k--;
                if(direction=='N') countS++;
                if(direction=='E') countW++;
            }
            else
            {
                if(direction=='N') countS--;
                if(direction=='E') countW--;
            }
        }
        ans = max(ans,countW+countS);        
    }
    k = copy;
    // case 2 changing N to S and W to E
    countN = 0, countE = 0, countW = 0, countS = 0;
    for (auto direction : s)
    {
        if(direction=='S') countS++;
        if(direction=='E') countE++;
        if(direction=='N' or direction=='W')
        {
            if(k)
            {
                k--;
                if(direction=='N') countS++;
                if(direction=='W') countE++;
            }
            else
            {
                if(direction=='N') countS--;
                if(direction=='W') countE--;
            }
        }
        ans = max(ans,countE+countS);        
    }
    k = copy;
    // case 3 changing S to N and E to W
    countN = 0, countE = 0, countW = 0, countS = 0;
    for (auto direction : s)
    {
        if(direction=='W') countW++;
        if(direction=='N') countN++;
        if(direction=='S' or direction=='E')
        {
            if(k)
            {
                k--;
                if(direction=='S') countN++;
                if(direction=='E') countW++;
            }
            else
            {
                if(direction=='S') countN--;
                if(direction=='E') countW--;
            }
        }
        ans = max(ans,countW+countN);        
    }
    k = copy;
    // case 4 changing S to N and W to E
    countN = 0, countE = 0, countW = 0, countS = 0;
    for (auto direction : s)
    {
        if(direction=='N') countN++;
        if(direction=='E') countE++;
        if(direction=='S' or direction=='W')
        {
            if(k)
            {
                k--;
                if(direction=='S') countN++;
                if(direction=='W') countE++;
            }
            else
            {
                if(direction=='S') countN--;
                if(direction=='W') countE--;
            }
        }
        ans = max(ans,countN+countE);        
    }

    return ans;
}

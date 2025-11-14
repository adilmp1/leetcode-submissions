int minOperations(vector<int> &a)
{
    int ones=0;
    int overall_gcd=a[0];
    for(int i=0;i<a.size();i++)
    {
        if(a[i]==1) ones++;
        overall_gcd = gcd(overall_gcd,a[i]);
    }

    if(overall_gcd!=1) return -1;
    
    if(ones>0) return a.size()-ones;
    int minOperationsToGetOne=INT_MAX;

    for(int i=0;i<a.size();i++)
    {
        int curr_gcd = a[i];
        for(int j=i+1;j<a.size();j++)
        {
            curr_gcd = gcd(curr_gcd,a[j]);
            if(curr_gcd==1)
            {
                minOperationsToGetOne = min(minOperationsToGetOne,j-i);
            }

        }
    }
    return minOperationsToGetOne+a.size()-1;
}

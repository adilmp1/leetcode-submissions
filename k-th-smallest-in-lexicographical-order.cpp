int countNumbersWithPrefix(int prefix,int n)
{
    long long firstNumber = prefix;
    long long nextNumber = prefix+1;

    int total_count=0;

    while(firstNumber<=n)
    {
        total_count+=static_cast<int>(min(n+1LL,nextNumber)-firstNumber);
        firstNumber*=10;
        nextNumber*=10;
    }
    return total_count;

}


int findKthNumber(int n, int k) 
{
    int curr = 1;
    k--;
    while(k>0)
    {
        int count = countNumbersWithPrefix(curr,n);
        if(k>=count)
        {
            curr++;
            k-=count;
        }
        else
        {
            curr*=10;
            k--;
        }
    }
    return curr;    
}

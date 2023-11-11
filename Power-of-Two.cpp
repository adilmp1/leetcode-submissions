bool isPowerOfTwo(int n)
{
    int mod=n%2;
    while(mod!=1 and n)
    {
        n/=2;
        mod=n%2;
    }
    if(mod==1)
    {
        return (n/2)==0;
    }
    return false;
}

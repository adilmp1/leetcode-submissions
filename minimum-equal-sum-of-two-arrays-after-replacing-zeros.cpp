long long minSum(vector<int> &a, vector<int> &b)
{
    int z1=0,z2=0;
    long long sum1 = 0;
    long long sum2 = 0;
    for(int i:a)
    {   
        sum1+=i;
        z1+=(!i);
    }
    for(int i:b)
    {   
        sum2+=i;
        z2+=(!i);
    }

    if((!z1 and !z2) and sum1!=sum2) return -1;
    if(!z1 and sum1<sum2+z2) return -1;
    if(!z2 and sum2<sum1+z1) return -1;     

    sum1+=z1;
    sum2+=z2;

    return max(sum1,sum2);
}

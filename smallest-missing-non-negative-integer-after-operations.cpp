int findSmallestInteger(vector<int> &a, int value)
{
    int n = a.size();
    vector<int> temp(value,0);
    for (int& i : a) 
    {
        if(i<0) 
        {
            long long v1 = abs(i);
            long long v2 = value;
            long long v3 = v1*v2;
            v3+=i;
            v3%=value;
            i=v3;
        }
        int idx = abs(i) % value;
        temp[idx]++;
    }
    int minValue=INT_MAX;
    int minIdx=-1;
    for(int i=0;i<value;i++)
    {
        if(temp[i]<minValue)
        {
            minValue=temp[i];
            minIdx=i;
        }
    }
    return minIdx+minValue*value;
}

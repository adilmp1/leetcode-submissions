bool increasingTriplet(vector<int> &v)
{
    int a = INT_MAX;
    int b = INT_MAX;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]<=a) a=v[i];
        else if(v[i]<=b) b=v[i];
        else return true;
    }
    return false;
}

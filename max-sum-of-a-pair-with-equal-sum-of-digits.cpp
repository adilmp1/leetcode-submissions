
int digit_sum(int n)
{
    int sum = 0;
    while (n)
    {
        sum += (n % 10);
        n /= 10;
    }
    return sum;
}
int maximumSum(vector<int> &a)
{
    unordered_map<int, vector<int>> mp;
    int ans = -1;
    for (int i : a)
    {
        int sum = digit_sum(i);
        bool flag=true;
        if (mp.find(sum)==mp.end() or mp[sum].size() < 2)
        {
            flag=false;
            mp[sum].push_back(i);
            auto &v = mp[sum];
            if(v.size()==2) ans = max(ans, v[0] + v[1]);
        }
        else
        {
            auto &v = mp[sum];
            ans = max(ans, v[0] + v[1]);
            int idx = 0;
            if (v[1] < v[0])
                idx = 1;
            if (v[idx] < i)
                v[idx] = i;
            ans = max(ans, v[0] + v[1]);
        }
    }
    return ans;
}

vector<int> maxSlidingWindow(vector<int> &a, int k)
{
    int n = a.size();
    priority_queue<int> pq;
    vector<int> ans;
    unordered_map<int,int> mp;
    int i;
    for(i=0;i<k;i++)
    {
        pq.push(a[i]);
        mp[a[i]]++;
    }
    cout<<pq.top()<<" ";
    ans.push_back(pq.top());
    int left=0;
    int right=i;
    while(right<n)
    {
        mp[a[left]]--;
        left++;
        pq.push(a[right]);
        mp[a[right]]++;
        while(mp[pq.top()]==0)
        {
            pq.pop();
        }
        ans.push_back(pq.top());
        cout<<ans.back()<<" ";
        right++;
    }
    return ans;
}

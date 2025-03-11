class Solution {
public:
    unordered_map<int,vector<int>> mp;
    Solution(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }

    }
    
    int pick(int target) {
        if(mp[target].size()==1)
        {
            return mp[target].back();
        }
        else
        {
            auto & a = mp[target];
            int n = a.size();
            return a[rand()%n];
        }
    }
};

    vector<string> ans;
    void helper(int idx,string digits,int n,string& temp,unordered_map<char,string> mp)
    {
        if(idx>=n) 
        {
            ans.push_back(temp);
            return;
        }
        const string str = mp[digits[idx]];
        for(int i=0;i<str.size();i++)
        {
            temp.push_back(str[i]);
            helper(idx+1,digits,n,temp,mp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) 
    {
        int n = digits.size();
        if(!n) return ans;
        unordered_map<char,string> mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        string temp="";
        helper(0,digits,n,temp,mp);
        return ans;
    }

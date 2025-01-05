string shiftingLetters(string s, vector<vector<int>> &shifts)
{
    int n = s.size();
    vector<int> count(n,0);
    for(auto & v:shifts)
    {
        bool flag=v[2];
        int start = v[0];
        int end = v[1];
        if(flag)
        {
            count[start]++;
            if(end<n-1) count[end+1]--;
        }
        else
        {
            count[start]--;
            if(end<n-1) count[end+1]++;
        }
    }
    int numberOfShifts=0;
    for(int i=0;i<n;i++)
    {
        numberOfShifts+=count[i];
        numberOfShifts%=26;
        
        if (numberOfShifts < 0)
            numberOfShifts +=
                26;

        s[i] = 'a' + (s[i] - 'a' + numberOfShifts) % 26;
    }
    return s;
}

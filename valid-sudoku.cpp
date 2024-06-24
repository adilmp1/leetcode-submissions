    bool isValidSudoku(vector<vector<char>>& a) 
    {
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        unordered_map<char,int> mp3;
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                char ch;
                int x = 3*(i/3)+j/3;
                int y = 3*(i%3)+j%3;
                ch=a[x][y];
                if(mp1.find(a[i][j])!=mp1.end() and a[i][j]!='.') return false;
                if(mp2.find(a[j][i])!=mp2.end() and a[j][i]!='.') return false;
                if(mp3.find(ch)!=mp3.end() and ch!='.') return false;
                mp1[a[i][j]]++;
                mp2[a[j][i]]++;
                mp3[ch]++;
            }
            mp1.clear();
            mp2.clear();
            mp3.clear();
        }
        return true;
    }

    bool doesValidArrayExist(vector<int>& a) {
        int ans=0;
        for(int i:a) ans^=i;
        return (ans==0);
    }

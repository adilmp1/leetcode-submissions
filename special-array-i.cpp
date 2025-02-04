    bool isArraySpecial(vector<int>& a) {
        for(int i=1;i<a.size();i++)
        {   
            int b = a[i]%2;
            int c = a[i-1]%2;
            if(b^c==0) return false;
        }
        return true;
    }

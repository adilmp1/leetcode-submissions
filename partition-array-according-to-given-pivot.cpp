    vector<int> pivotArray(vector<int>& a, int pivot) {
        vector<int> ans;
        vector<int> b;
        vector<int> c;

        for(auto i:a)
        {
            if(i<pivot) ans.push_back(i);
            else if(i==pivot) b.push_back(i);
            else if(i>pivot) c.push_back(i);
        }

        for(auto i:b) ans.push_back(i);
        for(auto i:c) ans.push_back(i);
        return ans;
    }

    int maxDistinct(string s) {
        unordered_set<char> l;
        for(char ch:s) l.insert(ch);
        return l.size();
    }

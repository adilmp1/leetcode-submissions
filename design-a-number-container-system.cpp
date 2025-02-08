class NumberContainers {
public:
    NumberContainers() {}
    map<int, set<int>> mp;
    map<int, int> id;
    void change(int index, int number) 
    {
        if (!id.count(index)) 
        {
            id[index] = number;
            mp[id[index]].insert(index);
        } 
        else 
        {
            mp[id[index]].erase(index);
            id[index] = number;
            mp[id[index]].insert(index);
        }
    }

    int find(int number) 
    {
        if (!mp[number].size()) return -1;
        return *mp[number].begin();
    }
};

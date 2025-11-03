struct pair_hash
{
    size_t operator()(const pair<int, int> &p) const
    {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

unordered_set<pair<int,int>,pair_hash> guards_set, walls_set, gcells;
void helper(int row, int col,int m,int n)
{
    for(int i=row+1;i<m and guards_set.find({i,col})==guards_set.end() and walls_set.find({i,col})==walls_set.end();i++) gcells.insert({i,col});
    for(int i=row-1;i>=0 and guards_set.find({i,col})==guards_set.end() and walls_set.find({i,col})==walls_set.end();i--) gcells.insert({i,col});
    for(int i=col+1;i<n and guards_set.find({row,i})==guards_set.end() and walls_set.find({row,i})==walls_set.end();i++) gcells.insert({row,i});
    for(int i=col-1;i>=0 and guards_set.find({row,i})==guards_set.end() and walls_set.find({row,i})==walls_set.end();i--) gcells.insert({row,i});
}

int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls)
{
    for(auto & pos:guards) guards_set.insert({pos[0],pos[1]});
    for(auto & pos:walls) walls_set.insert({pos[0],pos[1]});
    for(auto & pair:guards_set) helper(pair.first,pair.second,m,n);
    return m*n-(guards.size()+walls_set.size()+gcells.size());
}

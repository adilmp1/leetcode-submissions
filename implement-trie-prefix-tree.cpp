class node
{
public:
    bool isWord;
    vector<node *> child;
    node()
    {
        this->isWord = false;
        child = vector<node *>(26, nullptr);
    }
};

class Trie
{
public:
    node * root;
    Trie()
    {
        root = new node();
    }

    void insert(string s)
    {
        node * p = root;
        int idx=0;
        while(idx<s.size())
        {
            int pos = s[idx]-'a';
            if(!p->child[pos]) p->child[pos] = new node();
            idx++;
            p=p->child[pos];
        }
        p->isWord=true;
    }

    bool search(string s,bool prefix=false)
    {
        node * p = root;
        for(auto &c:s)
        {
            int pos = c-'a';
            if(!p->child[pos]) return false;
            p=p->child[pos];
        }
        if(prefix) return true;
        return p->isWord;
    }

    bool startsWith(string s)
    {
        return search(s,true);
    }
};

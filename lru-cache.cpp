class Node
{
public:
    int key;
    int val;
    Node *next;
    Node *prev;
    Node(int key, int val)
    {
        this->key = key;
        this->val = val;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache
{
public:
    int size;
    Node *head = NULL;
    Node *tail = NULL;
    unordered_map<int, Node *> mp;
    LRUCache(int capacity)
    {
        size = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void add(Node *p)
    {
        p->next = head->next;
        p->prev = head;
        head->next->prev = p;
        head->next = p;
    }

    void remove(Node *p)
    {
        p->prev->next = p->next;
        p->next->prev = p->prev;
    }

    int get(int key)
    {
        if (mp.find(key) == mp.end())
        {
            return -1;
        }
        Node *p = mp[key];
        remove(p);
        add(p);
        mp[key] = head->next;
        return p->val;
    }

    void put(int key, int value)
    {
        if (mp.find(key) == mp.end())
        {
            if (mp.size()==size)
            {
                mp.erase(tail->prev->key);
                remove(tail->prev);
            }
            Node *p = new Node(key, value);
            mp[key] = p;
            add(p);
        }
        Node *p = mp[key];
        p->val=value;
        remove(p);
        add(p);
        mp[key] = head->next;
    }
};

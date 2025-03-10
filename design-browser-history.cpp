class node {
public:
    string url;
    node * next;
    node * prev;

    node(string url)
    {
        this->url = url;
        next=nullptr;
        prev=nullptr;
    }
};


class BrowserHistory {
public:
    node * curr;
    BrowserHistory(string homepage) 
    {
        curr = new node(homepage);    
    }
    
    void visit(string url) {
        node * newNode = new node(url);
        curr->next = newNode;
        newNode->prev = curr;
        curr=curr->next;
    }
    
    string back(int steps) {
        while(curr->prev and steps--)
        {
            curr=curr->prev;
        }
        return curr->url;
    }
    
    string forward(int steps) {
        while(curr->next and steps--)
        {
            curr=curr->next;
        }
        return curr->url;
    }
};



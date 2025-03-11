class node{
public:
    int val;
    node * next;
    node * prev;
    node(int val)
    {
        this->val = val;
        next = nullptr;
        prev = nullptr;
    }
};


class MyCircularDeque {
public:
    int size;
    int count=0;
    node * head = nullptr;
    node * tail = nullptr;
    MyCircularDeque(int k) {
        size = k;
    }
    
    bool insertFront(int value) {
        if(count==size) return false;
        node * newNode = new node(value);
        if(!head)
        {
            head = newNode;
            tail = head;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        count++;
        return true;
    }
    
    bool insertLast(int value) {
        if(count==size) return false;
        node * newNode = new node(value);
        if(!head)
        {
            head = newNode;
            tail = head;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail=newNode;
        }
        count++;
        return true;
    }
    
    bool deleteFront() {
        if(!count) return false;
        if(count==1)
        {
            head=nullptr;
            tail=nullptr;
        }
        else
        {
            head->next->prev = nullptr;
            head=head->next;
        }
        count--;
        return true;
    }
    
    bool deleteLast() {
        if(!count) return false;
        if(count==1)
        {
            head=nullptr;
            tail=nullptr;
        }
        else
        {
            tail=tail->prev;
            tail->next = nullptr;
        }
        count--;
        return true;
    }
    
    int getFront() {
        if(!count) return -1;
        return head->val;
    }
    
    int getRear() {
        if(!count) return -1;
        return tail->val;
    }
    
    bool isEmpty() {
        return (count==0);
    }
    
    bool isFull() {
        return (count==size);
    }
};


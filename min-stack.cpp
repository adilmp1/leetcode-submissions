class MinStack {
public:
    stack<long long> s;
    long long mini = LLONG_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty())
        {
            s.push(val);
            mini=val;
            return;        
        }
        if(val>=mini)
        {
            s.push(val);
            return;
        }
        long long item = 2LL*val-mini;
        mini=val;
        s.push(item);
    }
    
    void pop() {
        if (s.empty()) return;

        long long topItem = s.top();
        s.pop();

        if (topItem < mini) {
            mini = 2LL * mini - topItem;
        }
    }
    
    int top() {
        if (s.empty()) return -1;

        long long topItem = s.top();
        if (topItem < mini) {
            return mini;
        } else {
            return topItem;
        }
    }
    
    int getMin() {
        return mini;
    }
};

    int lastStoneWeight(vector<int>& a) 
    {
        priority_queue<int> pq;
        for(int i:a) pq.push(i);

        while(!pq.empty())
        {
            if(pq.size()==1) return pq.top();
            int w1 = pq.top();pq.pop();
            int w2 = pq.top();pq.pop();
            if(w1==w2) continue;
            pq.push(abs(w1-w2));
        }
        return 0;
    }

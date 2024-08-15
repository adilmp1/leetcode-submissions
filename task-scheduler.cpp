int leastInterval(vector<char>& tasks, int n) {
    vector<int> freq(26, 0);
    for (char task : tasks) {
        freq[task - 'A']++;
    }
    
    priority_queue<int> pq;
    for (int f : freq) {
        if (f > 0) pq.push(f);
    }
    
    int cycles = 0;
    while (!pq.empty()) {
        vector<int> temp;
        int time = 0;
        
        // Schedule up to (n + 1) tasks
        for (int i = 0; i <= n; i++) {
            if (!pq.empty()) {
                temp.push_back(pq.top() - 1);
                pq.pop();
                time++;
            }
        }
        
        // Push remaining tasks back to the queue
        for (int t : temp) {
            if (t > 0) pq.push(t);
        }
        
        // If there are still tasks to process, add full cycle time (n + 1),
        // otherwise, add only the time taken
        cycles += !pq.empty() ? (n + 1) : time;
    }
    
    return cycles;
}

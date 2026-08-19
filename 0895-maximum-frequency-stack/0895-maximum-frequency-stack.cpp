class FreqStack {
public:
    priority_queue<pair<int, pair<int, int>>> pq; // store {freq,{pos, val}}
    unordered_map<int, int> freq;                 // store {freq, val}
    int pos = 0;
    FreqStack() {}

    void push(int val) {
        freq[val]++;
        pos++;

        pq.push({freq[val], {pos, val}});
    }

    int pop() {
        auto top = pq.top();

        int val = top.second.second;
        pq.pop();

        freq[val]--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
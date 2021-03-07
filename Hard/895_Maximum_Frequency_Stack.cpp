class FreqStack {
    private:
    int max_freq;
    map<int, int> freq;
    map<int, vector<int>> freq_stack;
    
public:
    FreqStack() : max_freq(0) {}
    
    void push(int x) {
        freq[x]++;
        freq_stack[freq[x]].push_back(x);
        if(freq[x] > max_freq)
            max_freq = freq[x];   
    }
    
    int pop() {
        int element = freq_stack[max_freq].back();
        freq_stack[max_freq].pop_back();
        freq[element]--;
        if (freq_stack[max_freq].empty())
            max_freq--;
        return element;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 */
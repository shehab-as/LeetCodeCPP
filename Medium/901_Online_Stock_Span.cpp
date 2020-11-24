class StockSpanner {
private:
    stack<pair<int,int>> stk;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int curr_span = 1;
        while(!stk.empty() && stk.top().first <= price) {
            curr_span += stk.top().second;
            stk.pop();
        }
        stk.push({price, curr_span});
        return curr_span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
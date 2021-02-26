class RecentCounter {
private:
    queue<int> Que;
    
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        while(!Que.empty()) {
            int oldest = Que.front();
            if( t - oldest > 3000)
                Que.pop();
            else 
                break;
        }
        Que.push(t);
        return (int) Que.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.empty())  return 0;
        priority_queue<int, vector<int>> pq (stones.begin(), stones.end());
        int x, y;
        while(!pq.empty()) {
            x = pq.top();   pq.pop();
            if(pq.empty())  return x;
            y = pq.top();   pq.pop();
            if(x - y > 0)   pq.push(x-y);
        }
        return 0;
    }
};
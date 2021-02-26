class Solution {
public:
    string reorganizeString(string S) {
        if(S.length() <= 1) {
            return S;
        }
        unordered_map<char, int> CharToFreq;
        for(char& c : S) {
            CharToFreq[c]++;
        }
        priority_queue<pair<int,char>, vector<pair<int,char>>> pq;
        for(auto it : CharToFreq) {
            pq.push({it.second, it.first});
        }
        string result = "";
        while(pq.size() > 1) {
            auto p1 = pq.top(); pq.pop();
            auto p2 = pq.top(); pq.pop();
            result += p1.second;
            result += p2.second;
            p1.first--; p2.first--;
            if(p1.first > 0) {
                pq.push(p1);
            }
            if(p2.first > 0) {
                pq.push(p2);
            }
        }
        if(!pq.empty()) {
            auto remaining_p = pq.top(); pq.pop();
            if(remaining_p.first > 1) {
                return "";
            }
            else {
                return result + remaining_p.second;
            }
        }
        return result;
        
    }
};
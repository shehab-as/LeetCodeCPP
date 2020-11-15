class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if(deck.size() < 2) return false;
        unordered_map<int, int> hmp;
        int result = 0;
        for(int& card : deck) 
            hmp[card]++;
        for(auto it : hmp)
            result = __gcd(it.second, result);
        return result > 1;
    }
};
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> jewels (J.begin(), J.end());
        int count = 0;
        for_each(S.begin(), S.end(), [&](char& c){ count += jewels.find(c) != jewels.end() ? 1 : 0; });
        return count;
    }
};
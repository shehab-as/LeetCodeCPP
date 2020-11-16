class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        if(bits.empty())    return true;
        bool isTwobit = (bits[0] == 1) ? true : false;
        for(int i = 1; i < bits.size() - 1; i++) {
            if(isTwobit)
                isTwobit = false;
            else if (!isTwobit && bits[i] == 1)
                isTwobit = true;
        }
        return (!isTwobit);
    }
};
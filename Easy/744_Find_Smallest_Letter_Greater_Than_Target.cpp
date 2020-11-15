class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if(letters.back() <= target)    return letters.front();
        int l = 0, h = letters.size() - 1;
        while (l < h ) {
            int m = l + (h - l)/2;
            if(target < letters[m])
                h = m;
            else
                l = m + 1;
        }
        return letters[l];
    }
};
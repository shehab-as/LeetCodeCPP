class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty())  return 0;
        int h_size = haystack.size();
        int n_size = needle.size();
        for(int i = 0; i <= h_size - n_size; i++) {
            int j = 0;
            while(haystack[i + j] == needle[j]) {
                if(j == n_size-1) return i;
                j++;
            }
        }
        return -1;
    }
};
class Solution {
public:
    void DEBUG(string dir, int s, int e) {
        cout<<dir<<" SEARCH: "<<s<<" TO "<<e<<endl;
    }
    int longestSubstring(string s, int k) {
        int N = (int) s.length();
        vector<int> count(26, 0);
        for(char& c : s)    
            count[(c - 'a')]++;
        int mid = 0;
        while(mid < N && count[(s[mid] - 'a')] >= k)    
            mid++;
        if(mid == N)    
            return N;
        int left = longestSubstring(s.substr(0, mid), k);
        while(mid < N && count[(s[mid] - 'a')] < k) 
            mid++;
        int right = longestSubstring(s.substr(mid), k);
        return max(left, right);
    }
};

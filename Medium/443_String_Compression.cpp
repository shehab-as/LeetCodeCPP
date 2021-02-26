class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size() < 2)    return chars.size();
        int i = 0, count = 0, t = 0;
        for(int j = 0; j < chars.size(); j++) {
            if(j+1 == chars.size() || chars[j+1] != chars[j]) {
                int m = t;
                chars[t++] = chars[j];
                if(j >= i + 1) {
                    string s = to_string(j - i + 1);
                    for(char& c : s)
                        chars[t++] = c;
                }
                i = j + 1;
                count += t - m;
            }
        }
        return count;
    }
};

// class Solution {
// public:
//     int compress(vector<char>& a) {
//         int i = 0, cnt = 0, t = 0;
//         for (int j = 0; j < a.size(); ++j) if (j+1 == a.size() || a[j+1] != a[j]) {
//             int m = t;
//             a[t++] = a[j];
//             if (j >= i + 1) {
//                 string s = to_string(j-i+1);
//                 for (char c:s) a[t++] = c;
//             }
//             i = j + 1;
//             cnt += t-m;
//         }
//         return cnt;
//     }
// };
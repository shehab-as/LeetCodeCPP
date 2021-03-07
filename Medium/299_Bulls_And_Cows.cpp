class Solution {
public:
    string getHint(string secret, string guess) {
        int counts[10] = {0};
        string output = "";
        int A = 0, B = 0;
        for(int i=0; i<guess.length(); i++) {
            char c1 = guess[i];
            char c2 = secret[i];
            if(c1 == c2) {
                A++;
                continue;
            }
            if(counts[c1 - '0'] > 0)
                B++;
            if(counts[c2 - '0'] < 0)
                B++;
            counts[c1 - '0']--;
            counts[c2 - '0']++;
        }
        
        return to_string(A) + "A" + to_string(B) + "B";
    }
};
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> freq(26, INT_MAX);
        for(string& word : A) {
            vector<int> curr_count(26, 0);
            for(char& c : word) curr_count[c - 'a']++;
            for(int i = 0; i < 26; i++)
                freq[i] = min(freq[i], curr_count[i]);
        }
        vector<string> result;
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < freq[i]; j++)
                result.push_back(string(1, i + 'a'));
        }
        return result;
    }
};
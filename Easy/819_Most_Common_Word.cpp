class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        for(int i = 0; i < paragraph.length(); i++) {
            paragraph[i] = isalpha(paragraph[i]) ? tolower(paragraph[i]) : ' ';
        }
        
        unordered_map<string, int> WordCount;
        unordered_set<string> BannedWords (banned.begin(), banned.end());
        istringstream iss(paragraph);
        string word;
        
        while(iss >> word) {
            if(BannedWords.find(word) == BannedWords.end())
                WordCount[word]++;
        }
        
        int freq = 0;
        string freq_res = "";
        for(auto it = WordCount.begin(); it != WordCount.end(); it++) {
            if(it->second >= freq) {
                freq_res = it->first;
                freq = it->second;
            }
        }
        return freq_res;
    }
};
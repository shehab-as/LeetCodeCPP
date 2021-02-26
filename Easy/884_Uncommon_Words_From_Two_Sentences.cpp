class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        vector<string> uncommonWords;
        unordered_map<string, int> WordCount;
        string word;
        string AB = A + " " + B;
        
        stringstream issAB(AB);
        while(issAB >> word) 
            WordCount[word]++;
        
        stringstream iss(AB);
        while(iss >> word) {
            if(WordCount[word] == 1)
                uncommonWords.push_back(word);
        }
            
        return uncommonWords;
    }
};
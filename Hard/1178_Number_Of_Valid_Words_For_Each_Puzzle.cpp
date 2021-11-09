class Solution {
private:
    int maskString(string s) {
        int mask = 0;
        for(char& c : s) {
            mask = mask | (1 << (c-'a'));
        }
        return mask;
    }
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int,int> mask_freq;
        for(int i = 0; i < words.size(); i++) {
            int curr_mask = maskString(words[i]);
            mask_freq[curr_mask]++;
        }
        int N = puzzles.size();
        vector<int> no_of_valid_words_per_puzzle(N, 0);
        for(int i = 0; i < N; i++) {
            string curr_puzzle = puzzles[i];
            int mask = maskString(curr_puzzle);
            int submask = mask;
            int first = 1 << (curr_puzzle[0] - 'a');
            int count = 0;
            while(submask) {
                if(submask & first) {
                    count += mask_freq[submask];
                }
                submask = submask - 1;
                submask = submask & mask;
            }
            no_of_valid_words_per_puzzle[i] = count;
        }
        return no_of_valid_words_per_puzzle;
    }
};
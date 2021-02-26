class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        if(words.empty())  return {};
        vector<string> result;
        unordered_set<char> first_row = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P'};
        unordered_set<char> second_row {'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L'};
        unordered_set<char> third_row {'Z', 'X', 'C', 'V', 'B', 'N', 'M'};
        for(string& word : words) {
            int found_in_rows [3] = {0, 0, 0};
            for(char c : word) {
                c = toupper(c);
                if(first_row.find(c) != first_row.end())
                    found_in_rows[0]++;
                else if(second_row.find(c) != second_row.end())
                    found_in_rows[1]++;
                else // if(third_row.find(c) != third_row.end())
                    found_in_rows[2]++;
            }
            if(found_in_rows[0] == word.length() || found_in_rows[1] == word.length() 
              || found_in_rows[2] == word.length())
                result.push_back(word);
        }
        return result;
        
    }
};
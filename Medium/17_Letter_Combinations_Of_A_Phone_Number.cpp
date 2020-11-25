class Solution {
private:
    unordered_map<int,string> IntToLetters = { 
        {'2', "abc"}, {'3', "def"},
        {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"},
        {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };
public:
    void GenerateCombinations(vector<string>& result, const string& digits, string curr, int index) {
        if (index >= digits.size())  {
            result.push_back(curr);
            return;
        }
        char digit = digits[index];
        string letters = IntToLetters[digit];
        for(int i = 0; i < letters.length(); i++) {
            GenerateCombinations(result, digits, curr + letters[i], index + 1);
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty())  return {};
        vector<string> result;
        GenerateCombinations(result, digits, "", 0);
        return result;
    }
};
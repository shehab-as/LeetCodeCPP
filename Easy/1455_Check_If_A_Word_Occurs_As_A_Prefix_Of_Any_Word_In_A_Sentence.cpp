class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int index = 1;
        istringstream iss(sentence);
        string word;
        while(getline(iss, word, ' ')) {
            cout<<word<<endl;
            if(word.rfind(searchWord, 0) != string::npos)
                return index;
            index++;
        }
        return -1;
    }
};
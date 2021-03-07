class Solution {
public:
    void swap(char& a, char& b) {
        int temp = a;
        a = b;
        b = temp;
    }
    int maximumSwap(int num) {
        string str_num = to_string(num);
        for(int i=0; i<str_num.length() - 1; i++) {
            pair<int, int> max_val (-1, -1);
            for(int j = i + 1; j<str_num.length(); j++) {
                if(max_val.first <= (str_num[j] - '0')) {
                    max_val.first = str_num[j] - '0';
                    max_val.second = j;
                }
            }
            if(max_val.first > str_num[i]-'0') {
                swap(str_num[i], str_num[max_val.second]);
                break;
            }
        }
        return stoi(str_num);
    }
};
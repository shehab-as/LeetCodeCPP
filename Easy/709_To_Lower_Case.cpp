class Solution {
public:
    string toLowerCase(string str) {
        transform(str.begin(), str.end(), str.begin(), [](char& c) {
            return tolower(c);
        });
        return str;
    }
};
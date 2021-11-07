class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") { return "0"; }
        vector<int> result(num1.size() + num2.size(), 0);
        int N1 = num1.length(), N2 = num2.length();
        for(int i = N1 - 1; i >= 0; i--) {
            for(int j = N2 - 1; j >= 0; j--) {
                result[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
                result[i + j] += result[i + j + 1] / 10;
                result[i + j + 1] %= 10;
            }
        }
        int i = 0;
        while(i < result.size() && result[i] == 0) { i++; }
        string res = "";
        while(i < result.size()) {
            res.push_back(result[i++] + '0');
        }
        return res;
    }
};


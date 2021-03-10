class Solution {
public:
    string intToRoman(int num) {
        string result = "";
        unordered_map<int, string> NumToRoman = { {1,"I"}, {4,"IV"}, {5,"V"}, {9,"IX"}, {10,"X"}, {40,"XL"}, {50,"L"}, {90,"XC"}, {100,"C"}, {400,"CD"}, {500,"D"}, {900,"CM"}, {1000,"M"} };
        vector<int> IDs = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        
        while ( num > 0 ) {
            for(int i = 0; i < IDs.size(); i++) {
                if( num >= IDs[i]) {
                    result += NumToRoman[IDs[i]];
                    num -= IDs[i];
                    break;
                }
            }
        }
        
        return result;
    }
};
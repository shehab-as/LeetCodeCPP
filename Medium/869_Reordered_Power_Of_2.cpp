class Solution {
public:
    string ToSortedStr(int N) {
        string result = to_string(N);
        sort(result.begin(), result.end());
        return result;
    }

    bool reorderedPowerOf2(int N) {
        string N_str = ToSortedStr(N);
        for(int i = 0; i < 32; i++) {
            if(N_str == ToSortedStr(1 << i))
                return true;
        }
            
        return false;
    }
};
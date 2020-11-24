class Solution {
public:
    int GetPower(int n) {
        if( n == 1 )    return 0;
        int val = n % 2 == 0 ? n / 2 : 3 * n + 1;
        return 1 + GetPower(val);
    }
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>> powList;
        for(int i = lo; i <= hi; i++) {
            powList.push_back({i, GetPower(i)});
        }
        partial_sort(powList.begin(), powList.begin() + k, powList.end(), [](auto p1, auto p2) {
            if(p1.second == p2.second)
                return p1.first < p2.first;
            return p1.second < p2.second;
        });
        return powList[k-1].first;
    }
};
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> v(n, 1);
        int IndexTwo = 0, IndexThree = 0, IndexFive = 0;
        for(int i = 1; i < n; i++) {
            v[i] = min(v[IndexTwo] * 2, min(v[IndexThree] * 3, v[IndexFive] * 5));
            if(v[i] == v[IndexTwo] * 2) 
                IndexTwo++;
            if(v[i] == v[IndexThree] * 3)
                IndexThree++;
            if(v[i] == v[IndexFive] * 5)
                IndexFive++;
        }
        return v[n-1];
    }
};
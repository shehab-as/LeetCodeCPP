class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int result = 0;
        unordered_set<int> s;
        for(int &element: A) {
            if(s.find(element) != s.end())
                return element;
            s.insert(element);
        }
        return result;
    }
};
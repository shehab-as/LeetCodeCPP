class Solution {
public:
    vector<int> distributeCandies(int candies, int num) {
        vector<int> people(num);
        for(int i = 0; candies > 0; i++) {
            people[i % num] += min(candies, i+1);
            candies -= i + 1;
        }
        return people;
    }
};
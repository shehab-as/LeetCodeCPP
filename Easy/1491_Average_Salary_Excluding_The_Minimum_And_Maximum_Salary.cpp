class Solution {
public:
    double average(vector<int>& salary) {
        int N = salary.size();
        int max_salary = INT_MIN, min_salary = INT_MAX;
        int sum = 0;
        for(int& s : salary) {
            max_salary = max(max_salary, s);
            min_salary = min(min_salary, s);
            sum += s;
        }
        return (double)(sum - (max_salary + min_salary)) / (N - 2);
    }
};
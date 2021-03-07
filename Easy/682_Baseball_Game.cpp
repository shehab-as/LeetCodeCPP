class Solution {
public:
    int calPoints(vector<string>& ops) {
        if(ops.size() < 1)
            return 0;
        int total_points = 0;
        stack<int> score_history;
        for(string & op : ops) {
            if(op[0] == 'C') {
                total_points -= score_history.top();
                score_history.pop();
            }
            else if(op[0] == '+') {
                int last = score_history.top();
                score_history.pop();
                int before_last = score_history.top();
                total_points = total_points + last + before_last;
                score_history.push(last);
                score_history.push(last + before_last);
            }
            else if(op[0] == 'D') {
                int last = score_history.top();
                total_points = total_points + (last * 2);
                score_history.push(last * 2);
            }
            else {
                int number = stoi(op);
                total_points += number;
                score_history.push(number);
            }
        }
        return total_points;
    }
};
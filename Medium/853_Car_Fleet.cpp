class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int, double> car_time;
        for(int i = 0; i< position.size(); i++)
            car_time[-position[i]] = (double) (target - position[i])/speed[i]; 
        int res = 0;
        double curr = 0.0;
        for(auto it : car_time) {
            if(it.second > curr) {
                curr = it.second;
                res++;
            }
        }
        return res;
    }
};


//     int carFleet(int target, vector<int>& pos, vector<int>& speed) {
//         map<int, double> m;
//         for (int i = 0; i < pos.size(); i++) m[-pos[i]] = (double)(target - pos[i]) / speed[i];
//         int res = 0; double cur = 0;
//         for (auto it : m) if (it.second > cur) cur = it.second, res++;
//         return res;
//     }
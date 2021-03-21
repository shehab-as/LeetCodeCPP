class UndergroundSystem {
private:
    unordered_map<string, vector<double>> StationBook;
    unordered_map<int, pair<string, int>> RiderFromStation;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        RiderFromStation[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        pair<string, int> station_time = RiderFromStation[id];
        string Start = station_time.first, End = stationName;
        int t1 = station_time.second, t2 = t;
        
        StationBook[Start + End].push_back(t2 - t1);
    }
    
    double getAverageTime(string startStation, string endStation) {
        vector<double> durations = StationBook[startStation + endStation];
        double avg = 0.0;
        double sum = 0.0;
        int N = durations.size();
        for(double d : durations) {
            sum += d;
        }
        avg = sum / N;
        return avg;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
class Solution {
private:
    int getDistance(const vector<int>& distance, int start, int destination) {
        int d = 0, N = distance.size();
        while(start != destination) {
            d += distance[start];
            start = (start + 1) % N;
        }
        return d;
    }
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int forward_distance = getDistance(distance, start, destination);
        int backward_distance = getDistance(distance, destination, start);
        return min(forward_distance, backward_distance);
    }
};
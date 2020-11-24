class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourAngle = ((hour % 12) + minutes/60.0) * 30;
        double minutesAngle = minutes * 6;

        double result = abs(hourAngle - minutesAngle);
        return min(result, 360-result);
    }
};
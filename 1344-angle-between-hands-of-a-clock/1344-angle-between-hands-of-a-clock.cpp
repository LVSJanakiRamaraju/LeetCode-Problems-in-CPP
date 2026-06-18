class Solution {
public:
    double angleClock(int hour, int minutes) {
        hour = hour % 12;
        double hour_angle = 30 * hour + 0.5 * double(minutes);
        int minute_angle = 6 * minutes;
        double diff = abs(hour_angle - minute_angle);
        return min(diff, 360 - diff);
    }
};
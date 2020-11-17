class Solution {
public:
    bool IsLeapYear(int year) {
        return year % 400 == 0 || (year % 100 != 0 && year % 4 == 0);
    }
    int GetTotalDays(int day, int month, int year) {
        int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int total_days = day;
        for(int y = 1971; y < year; y++) {
            total_days += 365;
            if(IsLeapYear(y))
                total_days++;
        }
        for(int m = 0; m < month - 1; m++) {
            total_days += months[m];
        }
        if(month > 2 && IsLeapYear(year))
            total_days++;
        return total_days;
    }
    string dayOfTheWeek(int day, int month, int year) {
        string Days[] = {"Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday"};
        int total_days = GetTotalDays(day, month, year);
        // cout<<total_days<<" | "<<total_days%7<<endl;
        return Days[total_days % 7];
    }
};
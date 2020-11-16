class Solution {
private:
    int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
public:
    bool isLeapYear(int year) {
        return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
    }
    int DaysFromDate(string date) {
        int year, month, day;
        year = stoi(date.substr(0, 4));
        month = stoi(date.substr(5, 2));
        day = stoi(date.substr(8));
        
        int total_days = 0;
        for(int y = 1971; y < year; y++)
            total_days += isLeapYear(y) ? 366 : 365;
        for(int m = 0; m < month - 1; m++)
            total_days += days[m];
        if(month > 2 && isLeapYear(year))
            total_days++;
        total_days += day;
        return total_days;
    }

    int daysBetweenDates(string date1, string date2) {
        return abs(DaysFromDate(date1) - DaysFromDate(date2));
    }
};
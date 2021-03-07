class MyCalendar {
private:
    struct CMP {
        bool operator()(const pair<int,int>&A, const pair<int,int>&B) const {
            return A.second <= B.first;
        }
    };
    set<pair<int, int>, CMP> events;
    
public:
    
    MyCalendar(){
    }
    bool book(int start, int end) {
        if(events.count(pair<int,int>(start, end))) {
            return false;
        }
        events.insert(pair<int, int>(start, end));
        return true;
    }
};


/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */
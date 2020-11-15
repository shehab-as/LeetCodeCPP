public:
    bool match(char &a, char &b) {
        return (a == '(' && b == ')' ||
               a == '[' && b == ']' ||
               a == '{' && b == '}');
    }
    bool isValid(string s) {
        if(s.empty())   return true;
        stack<char> opened_bracks;
        for(char &c : s) {
            if(c == '(' || c == '[' || c == '{')
                opened_bracks.push(c);
            else if(opened_bracks.empty())
                return false;
            else {
                if(match(opened_bracks.top(), c))
                    opened_bracks.pop();
                else
                    return false;
            }
        }
        return (opened_bracks.empty());
    }
};
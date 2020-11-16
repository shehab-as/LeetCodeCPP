class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> stackS, stackT;
        for(char& c : S) {
            if( c == '#' && !stackS.empty())
                stackS.pop();
            else if(c != '#')
                stackS.push(c);
        }
        for(char& c : T) {
            if( c == '#' && !stackT.empty())
                stackT.pop();
            else if(c != '#')
                stackT.push(c);
        }
        return stackS == stackT;
    }
};
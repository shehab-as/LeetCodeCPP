class Solution {
public:
    void getAllValid(vector<string>& res, string s, int index, int dots, string Addr) {
        if(index == s.length() && dots == 4) {
            Addr.pop_back();
            res.push_back(Addr);
            return;
        }
        if(dots > 3) 
            return;
        if(index + 1 > s.length())  
            return;
        Addr += s.substr(index, 1) + '.';
        getAllValid(res, s, index + 1, dots + 1, Addr);
        
        Addr.erase(Addr.end() - 2, Addr.end());
        
        if(index + 2 > s.length() || s[index] == '0')   
            return;
        Addr += s.substr(index, 2) + '.';
        getAllValid(res, s, index + 2, dots + 1, Addr);
        
        Addr.erase(Addr.end() - 3, Addr.end());
        
        if(index + 3 > s.length() || stoi(s.substr(index, 3)) > 255)    
            return;
        Addr += s.substr(index, 3) + '.';
        getAllValid(res, s, index + 3, dots + 1, Addr);
        
        Addr.erase(Addr.end() - 4, Addr.end());
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        getAllValid(res, s, 0, 0, "");
        return res;
    }
};
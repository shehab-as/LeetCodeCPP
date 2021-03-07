class Solution {
public:
    string count(string s)
    {
        string x = "";
        bool rep = false;
        int counter = 0;
        for(int i=0; i<s.length(); i++)
        {
            if(i + 1 == s.length())             // 1
            {
                if(!rep)            // unique.
                {
                    char c = '1';
                    x = x + c + s[i];
                    break;
                }
                else                // rep and ending digit.
                {
                    counter++;
                    char c = counter + '0';
                    x = x + c + s[i];
                    break;
                }
            }
            
            else if(s[i] != s[i+1])             // 2
            {
                if(rep)
                {
                    counter ++;
                    char c = counter + '0';
                    x = x + c + s[i];
                    rep = false;
                    counter = 0;
                }
                else        // !rep
                {
                    char c = '1';
                    x = x + c + s[i];
                }
            }
            
            else if (s[i] == s[i+1])
            {
                if(rep)
                    counter++;
                else        // !rep
                {
                    rep = true;
                    counter ++;
                }
            }   
        }
        
        return x;
    }
    
    string countAndSay(int n) {
        string s = "1";
        string t;
        if(n == 1)
            return s;
        for(int i = 1; i < n; i++)
        {
            t = count(s);
            s = t;
        }
        return s;
    }
};
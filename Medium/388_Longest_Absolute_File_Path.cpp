class Solution {
public:
    bool isAFile(const string& item) {
        return (item.find('.', 0) != string::npos);
    }
    int countAndRemoveTabs(string& item) {
        int tabs = 0;
        int i= 0;
        while(i < item.length() && i != string::npos) {
            int nI = item.find('\t', i);
            if(nI == string::npos)  break;
            tabs++;
            item.erase(nI, 1);
            i = nI;
        }
        return tabs;
    }
    int lengthLongestPath(string input) {
        deque<string> dq;
        int result = 0;
        int i = 0;
        
        while(i < input.length()) {
            int nI = input.find('\n', i);
            if(nI == string::npos)  // take remaining path.
                nI = (int) input.size();
            string item = input.substr(i, nI - i);
            int tabs = countAndRemoveTabs(item);
            bool isFile = isAFile(item);
            while(tabs < dq.size()) {
                dq.pop_back();
            }
            
            if(isFile) {
                string fileWithPath = "";
                for(string ele : dq) {
                    fileWithPath += ele;
                }
                fileWithPath += item;
                result = max(result, (int) fileWithPath.size());
            }
            else {
                dq.push_back(item + '/');
            }
            i = nI + 1;
        }
        return result;
    }
};
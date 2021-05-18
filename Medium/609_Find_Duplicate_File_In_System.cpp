class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> FilesMap;
        string line, info;
        for(string& path : paths) {
            istringstream iss(path);
            line.clear();
            getline(iss, line, ' ');
            info = line;
            while(getline(iss, line, '(')) {
                string curr_path = info + "/" + line;
                getline(iss, line, ' ');
                line.pop_back();    // get rid of ')'
                FilesMap[line].push_back(curr_path);
            }
        }
        vector<vector<string>> duplicateFiles;
        for(auto it : FilesMap) {
            if(it.second.size() > 1) {
                duplicateFiles.push_back(it.second);
            }
        }
        return duplicateFiles;
    }
};
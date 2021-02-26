class Solution {
public:
    string preprocessEmail(const string& s) {
        string result = "";
        for(char c : s) {
            if(c == '+')    break;
            if(c == '.')    continue;
            result += c;
        }
        return result;
    }
    int numUniqueEmails(vector<string>& emails) {
        unordered_map<string, int> EmailLookup;
        for(string& email : emails) {
            size_t i = email.find('@');
            string local_name = email.substr(0, i);
            string domain_name = email.substr(i, email.length());
            local_name = preprocessEmail(local_name);
            cout<<local_name+domain_name<<endl;
            EmailLookup[local_name + domain_name]++;
        }
        return EmailLookup.size();
    }
};
class Solution {
public:
    void ReplaceAll(string& text, const string key, const string value) {
        size_t pos = text.find(key);
        while(pos != string::npos) {
            text.replace(pos, key.length(), value);
            pos = text.find(key, pos+1);
        }
    }
    string entityParser(string text) {
        const string keys[] = {"&quot;", "&apos;", "&amp;", "&gt;", "&lt;", "&frasl;"};
        const string values[] = {"\"", "\'", "&", ">", "<", "/"};
        int N = sizeof(keys)/sizeof(keys[0]);
        for(int i = 0; i < N; i++)
            ReplaceAll(text, keys[i], values[i]);
        return text;
    }
};
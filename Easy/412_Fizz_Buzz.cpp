class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        for(int i = 1; i <= n; i++) {
            string entry = "";
            if( i % 3 == 0 && i % 5 == 0)
                entry += "FizzBuzz";
            else if (i % 5 == 0)
                entry += "Buzz";
            else if(i % 3 == 0)
                entry += "Fizz";
            else
                entry = to_string(i);
            result.push_back(entry);
        }
        return result;
    }
};
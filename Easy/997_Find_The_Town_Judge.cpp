class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        unordered_set<int> trusting_people;
        unordered_map<int, int> trusted_people;
        for(int i=0; i<trust.size(); i++) {
            trusting_people.insert(trust[i][0]);
            trusted_people[trust[i][1]]++;
        }
        int index = -1;
        for(int j=1; j<=N; j++) {
            if(trusting_people.find(j) == trusting_people.end() 
              && trusted_people[j] == (N-1) ) {
                index = j;
                break;
            }
        }
        return index;
    }
};
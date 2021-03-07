class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        if(list1.size() < 1 || list2.size() < 1)
            return {};
        unordered_map<string, int> hmp;
        for(int i=0; i<list1.size(); i++)
            hmp[list1[i]] = i;
        
        vector<string> result;
        int comm_index = INT_MAX;

        for(int j=0; j<list2.size(); j++) {
            if(hmp.find(list2[j]) != hmp.end()) {
                int index = j + hmp[list2[j]];
                if(index < comm_index) 
                    comm_index = index;
            }
        }
        
        for(int k=0; k<list2.size(); k++)
            if(hmp.find(list2[k]) != hmp.end() && (k+hmp[list2[k]]) == comm_index)
                result.push_back(list2[k]);
        
        return result;
    }
};
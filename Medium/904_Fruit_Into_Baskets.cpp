class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int total_max = 0;
        if(tree.size() == 0)
            return 0;
        int a = tree[0], b = INT_MIN;
        int curr_max = 1;
        for(int i=1; i<tree.size(); i++)
        {
            if(tree[i] == a || tree[i] == b)
                curr_max++;
            if(tree[i] != a && b == INT_MIN)
            {
                b = tree[i];
                curr_max++;
            }
            else if(tree[i] != a && tree[i] != b)
            {
                total_max = max(total_max, curr_max);
                curr_max = 2;
                
                a = tree[i-1];
                b = tree[i];
                int j = i-2;
                while(tree[j] == a)
                {
                    j--;
                    curr_max++;
                }
            }
        }
        total_max = max(total_max, curr_max);
        return total_max;
    }
};
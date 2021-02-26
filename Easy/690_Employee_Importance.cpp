/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        stack<Employee*> stk;
        unordered_map<int, Employee*> employees_dir;
        for(auto& e : employees) {
            employees_dir[e->id] = e;
            if(e->id == id)
                stk.push(e);
        }
        int result = 0;
        while(!stk.empty()) {
            auto temp = stk.top();
            stk.pop();
            result += temp->importance;
            vector<int> subs = temp->subordinates;
            for(int j = 0; j < subs.size(); j++)
                stk.push(employees_dir[subs[j]]);
        }
        return result;
        
    }
};
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<string> solution(vector<vector<int>> queries) {
    vector<string> answer;
    for(int i = 0; i < queries.size(); i++){
        int n = queries[i][0];
        int p = queries[i][1] - 1;
        stack<int> pos_st;
        
        for(int j = 0; j < n - 1; j++){
            pos_st.push(p % 4);
            p /= 4;
        }
        
        string parent = "Rr";
        while(!pos_st.empty()){
            int pos = pos_st.top();
            pos_st.pop();
            
            if(parent == "Rr"){
                if(pos == 0)    parent = "RR";
                else if(pos == 3)   parent = "rr";
            }
            else    break;
        }
        answer.push_back(parent);
    }  
    return answer;
}

#include <string>
#include <vector>

using namespace std;

bool visited[10] = {false, };
int max_sum = -1;

void dfs(int sum, int idx, const vector<vector<int>> ability){
    if(idx >= ability[0].size()){
        if(sum > max_sum)   max_sum = sum;
        return;
    }
    
    for(int i = 0; i < ability.size(); i++){
        if(visited[i])  continue;
        visited[i] = true;
        dfs(sum + ability[i][idx], idx + 1, ability);
        visited[i] = false;
    }
}

int solution(vector<vector<int>> ability) {
    dfs(0, 0, ability);
    return max_sum;
}

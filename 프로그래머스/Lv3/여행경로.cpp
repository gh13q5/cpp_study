#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> answer;
bool visited[100001];
bool is_finish = false;     // 경로 탐색이 끝났는지 확인

void dfs(string start, vector<vector<string>> &tickets){
    if(answer.size() == tickets.size()) is_finish = true;
    
    answer.push_back(start);
    for(int i = 0; i < tickets.size(); i++){
        if(visited[i])  continue;
        if(tickets[i][0] == start){
            visited[i] = true;
            dfs(tickets[i][1], tickets);
            if(!is_finish){
                answer.pop_back();
                visited[i] = false;
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) { 
    sort(tickets.begin(), tickets.end());       // 오름차순 정렬
    dfs("ICN", tickets);
    return answer;
}

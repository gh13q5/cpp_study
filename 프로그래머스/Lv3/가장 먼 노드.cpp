#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int max_dist = 1;
    vector<bool> visited(n, false);
    vector<int> distance(n, 0);
    queue<int> edge_q;
    
    sort(edge.begin(), edge.end());
    
    edge_q.push(1);     visited[0] = true;
    while(!edge_q.empty()){
        int q_size = edge_q.size();
        for(int i = 0; i < q_size; i++){
            int cur = edge_q.front();
            edge_q.pop();
            for(int j = 0; j < edge.size(); j++){
                if(edge[j][0] != cur && edge[j][1] != cur)  continue;
                int next = edge[j][0] == cur ? edge[j][1] : edge[j][0];     // [2,5]인지 [5,2]인지
                if(visited[next - 1])   continue;
                
                edge_q.push(next);
                distance[next - 1] = max_dist;
                visited[next - 1] = true;
            }
        }
        max_dist++;
    }
    
    for(int i = 0; i < distance.size(); i++)
        if(distance[i] == max_dist - 2) answer++;       // 마지막에 max_dist가 2번 더해져서 2를 빼줌
    
    return answer;
}

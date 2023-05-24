#include <vector>
#include <queue>

using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    vector<int> dist(N, 500001);
    dist[0] = 0;
    priority_queue<pair<int, int>> pq;      // pair<노드, 거리>
    pq.push(make_pair(0, 0)); 
    
    vector<vector<pair<int, int>>> path(N);         // 각 정점에서 갈 수 있는 마을 모음
    for(int i = 0; i < road.size(); i++){
        path[road[i][0] - 1].push_back(make_pair(road[i][1] - 1, road[i][2]));
        path[road[i][1] - 1].push_back(make_pair(road[i][0] - 1, road[i][2]));
    }
    
    while(!pq.empty()){
        int cur_v = pq.top().first;
        int cur_c = pq.top().second;
        pq.pop();
        for(auto p : path[cur_v]){
            int next_v = p.first;
            int next_c = cur_c + p.second;
            if(next_c < dist[next_v]){
                dist[next_v] = next_c;
                pq.push(make_pair(next_v, next_c));
            }
        }
    }
    
    int cnt = 0;
    for(int i = 0; i < dist.size(); i++)        // K보다 작거나 같은 거리 세기
        if(dist[i] <= K)    cnt++;
    return cnt;
}

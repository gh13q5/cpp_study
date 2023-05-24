#include <string>
#include <vector>
#include <set>

using namespace std;

int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};        // 0~7일 때 이동 좌표

int solution(vector<int> arrows) {
    int answer = 0;
    set<pair<int, int>> map;     // pair<x, y> 거쳐간 좌표들
    set<pair<pair<int, int>, pair<int, int>>> visited;      // pair<<이전x, 이전y>, <현재x, 현재y> - 방문한 간선인지
    pair<int, int> first_cur;
    pair<int, int> second_cur = make_pair(0, 0);    // pair<x, y> 현재 위치
    
    map.insert(second_cur);
    for(int i = 0; i < arrows.size(); i++){
        pair<int, int> prev = second_cur;   // 이전 위치 저장
        first_cur = make_pair(second_cur.first + dx[arrows[i]], second_cur.second + dy[arrows[i]]);
        second_cur = make_pair(first_cur.first + dx[arrows[i]], first_cur.second + dy[arrows[i]]);
        
        pair<pair<int, int>, pair<int, int>> cur_edge = make_pair(prev, second_cur);        // 현재 간선
        pair<pair<int, int>, pair<int, int>> cur_edge_r = make_pair(second_cur, prev);
        
        if(map.count(first_cur) != 0 && visited.count(cur_edge) == 0 && visited.count(cur_edge_r) == 0)    answer++;
        if(map.count(second_cur) != 0 && visited.count(cur_edge) == 0 && visited.count(cur_edge_r) == 0)   answer++;
        
        map.insert(first_cur);
        map.insert(second_cur);
        visited.insert(make_pair(prev, second_cur));
    }
    
    return answer;
}

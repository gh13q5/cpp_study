#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};  // 상-우-하-좌 (시계방향)

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    bool map[104][104] = {false, };       // 0 : 못 가는 곳 - 1 : 테두리 -> 2배로 늘림
    queue<pair<int, int>> location_q;       // pair<x, y>
    
    for(auto rect : rectangle){
        for(int i = rect[1] * 2; i <= rect[3] * 2; i++)
            for(int j = rect[0] * 2; j <= rect[2] * 2; j++)
                if(i == rect[1] * 2 || i == rect[3] * 2 || j == rect[0] * 2 || j == rect[2] * 2)    map[i][j] = true;
    }
    
    for(auto rect : rectangle){
        for(int i = rect[1] * 2; i <= rect[3] * 2; i++)
            for(int j = rect[0] * 2; j <= rect[2] * 2; j++)
                if(i != rect[1] * 2 && i != rect[3] * 2 && j != rect[0] * 2 && j != rect[2] * 2)    map[i][j] = false;
    }

    location_q.push(make_pair(characterX * 2, characterY * 2));
    while(!location_q.empty()){
        int q_size = location_q.size();
        for(int i = 0; i < q_size; i++){
            int cur_x = location_q.front().first;
            int cur_y = location_q.front().second;
            location_q.pop();
            for(int j = 0; j < 4; j++){
                int next_x = cur_x + dx[j];
                int next_y = cur_y + dy[j];

                if(!map[next_y][next_x])    continue;
                if(next_x == itemX * 2 && next_y == itemY * 2)   return (answer + 1) / 2;
                
                map[cur_y][cur_x] = 0;
                location_q.push(make_pair(next_x, next_y));
            }
        }
        answer++;
    }
    
    return -1;
}

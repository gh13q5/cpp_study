#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<vector<int>> map(rows, vector<int>(columns, 0));
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < columns; j++)
            map[i][j] = i * columns + j + 1;
    
    vector<int> answer;
    for(auto q : queries){
        pair<int, int> start = {q[0] - 1, q[1] - 1};
        pair<int, int> end = {q[2] - 1, q[3] - 1};
        
        int n = map[start.first][start.second];
        int min_n = n;
        int cur_x = start.first,   cur_y = start.second + 1;
        while(cur_x >= start.first){
            int tmp = map[cur_x][cur_y];
            map[cur_x][cur_y] = n;
            n = tmp;
            min_n = min(min_n, n);
            
            if(cur_y == start.second)   cur_x--;        // 회전
            else if(cur_x == end.first) cur_y--;
            else if(cur_y == end.second)    cur_x++;
            else    cur_y++;
        }
        answer.push_back(min_n);
    }
     
    return answer;
}

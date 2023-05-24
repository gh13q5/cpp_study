#include <string>
#include <vector>

using namespace std;

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    int path[4] = {0, 0, 0, 0};     // d, l, r, u
    
    k -= abs(x - r) + abs(y - c);
    if(k < 0 || k % 2 == 1)   return "impossible";        // 출발지와 목적지의 거리 차가 홀수이면 불가능
    
    if(x - r < 0)       path[0] += (r - x);
    else if(x - r > 0)  path[3] += (x - r);
    if(y - c < 0)       path[2] += (c - y);
    else if(y - c > 0)  path[1] += (y - c);
    
    answer.append(path[0], 'd');
    int ud_cnt = (k / 2 > n - (x + path[0])) ? (n - (x + path[0])) : (k / 2);       // 위아래로 몇 번 왔다갔다 하는지
    answer.append(ud_cnt, 'd');
    path[3] += ud_cnt;
    k -= ud_cnt * 2;
    
    answer.append(path[1], 'l');
    int lr_cnt = (k / 2 > y - path[1] - 1) ? (y - path[1] - 1) : (k / 2);       // 좌우로 몇 번 왔다갔다 하는지
    answer.append(lr_cnt, 'l');
    path[2] += lr_cnt;
    k -= lr_cnt * 2;
    
    for(int i = 0; i < k / 2; i++){
        answer += 'r';      answer += 'l';      // 남은 거리
    }
    answer.append(path[2], 'r');
    answer.append(path[3], 'u');
    
    return answer;
}

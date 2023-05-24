#include <string>
#include <set>

using namespace std;

int solution(string dirs) {
    pair<int, int> cur(0, 0);
    set<pair<pair<int, int>, pair<int, int>>> visited;		// pair<현재 정점, 다음 정점>
    for(auto d : dirs){
        pair<int, int> next = cur;
        switch(d){
            case 'U':
                next.second++;
                break;
            case 'D':
                next.second--;
                break;
            case 'L':
                next.first--;
                break;
            case 'R':
                next.first++;
                break;
        }
        if(next.first > 5 || next.first < -5 || next.second > 5 || next.second < -5)    continue;
        visited.insert(make_pair(cur, next));
        visited.insert(make_pair(next, cur));
        cur = next;
    }
    return visited.size() / 2;
}

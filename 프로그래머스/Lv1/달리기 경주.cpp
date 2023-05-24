#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string, int> rank;     // map<이름, 순위>
    for(int i = 0; i < players.size(); i++)
        rank.insert({players[i], i + 1});
    
    vector<string> answer = players;
    for(string c : callings){
        int cur = rank[c] - 1;
        swap(answer[cur], answer[cur - 1]);
        rank[c] -= 1;
        rank[answer[cur]] += 1;
    }
    return answer;
}

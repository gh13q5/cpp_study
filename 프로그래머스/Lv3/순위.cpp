#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<int> round_cnt(n, 0);
    vector<vector<bool>> is_win(n, vector<bool>(n, false));
    
    for(int i = 0; i < results.size(); i++)
        is_win[results[i][0] - 1][results[i][1] - 1] = true;
    
    for(int v= 0; v < n; v++){
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(is_win[i][v] && is_win[v][j])    is_win[i][j] = true;
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < is_win[0].size(); j++)
            if(is_win[i][j]){
                round_cnt[i]++;
                round_cnt[j]++;
            }
    }
        
    for(int i = 0; i < n; i++)
        if(round_cnt[i] == n - 1)   answer++;   
        
    return answer;
}

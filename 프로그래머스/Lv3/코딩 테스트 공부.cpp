#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems) {
    int dp[151][151];
    fill(&dp[0][0], &dp[150][150], 99999999);
    
    int alp_max = -1, cop_max = -1;         // 최댓값 찾기
    for(int i = 0; i < problems.size(); i++){
        if(problems[i][0] > alp_max)    alp_max = problems[i][0];
        if(problems[i][1] > cop_max)    cop_max = problems[i][1];
    }
    alp = min(alp, alp_max);        cop = min(cop, cop_max);
    
    dp[alp][cop] = 0;
    for(int i = alp; i <= alp_max; i++){
        for(int j = cop; j <= cop_max; j++){
            if(i < alp_max)     dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
            if(j < cop_max)     dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
            
            for(auto p : problems){
                if(i >= p[0] && j >=p[1]){
                    int a = min(i + p[2], alp_max);     int c = min(j + p[3], cop_max);
                    dp[a][c] = min(dp[a][c], dp[i][j] + p[4]);
                }
            }
        }
    }
    
    return dp[alp_max][cop_max];
}

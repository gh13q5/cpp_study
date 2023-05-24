#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int mod = 1000000007;
    int path[101][101] = {0, };
    
    for(int i = 0; i < puddles.size(); i++)
        path[puddles[i][1]][puddles[i][0]] = -1;     // 웅덩이 표시
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(i == 1 && j == 1)
                path[i][j] = 1;
            else if(path[i][j] == -1)
                path[i][j] = 0;
            else
                path[i][j] = (path[i - 1][j] + path[i][j - 1]) % mod;
        }
    }
    
    return path[n][m];
}

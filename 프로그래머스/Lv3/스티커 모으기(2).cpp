#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> sticker){
    if(sticker.size() == 1)     return sticker[0];
    
    vector<int> dp(sticker.size());
    
    dp[0] = sticker[0],    dp[1] = dp[0];   // 첫번째 원소 포함
    for(int i = 2; i < sticker.size() - 1; i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + sticker[i]);
    int sum1 = *max_element(dp.begin(), dp.end());
    
    dp[0] = 0;      // 첫번째 원소 미포함
    for(int i = 1; i < sticker.size(); i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + sticker[i]);
    int sum2 = *max_element(dp.begin(), dp.end());
    
    return max(sum1, sum2);
}

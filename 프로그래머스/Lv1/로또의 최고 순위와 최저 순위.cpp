#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    int cnt = 0,    zero_cnt = 0;
    for(int i = 0; i < lottos.size(); i++){
        if(lottos[i] == 0){
            zero_cnt++;
            continue;
        }
        for(int j = 0; j < win_nums.size(); j++)
            if(lottos[i] == win_nums[j])    cnt++;
    }
    
    int best = (cnt + zero_cnt > 1) ? 7 - (cnt + zero_cnt) : 6;
    int worst = (cnt > 1) ? 7 - cnt : 6;
    return {best, worst};
}

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    sort(d.begin(), d.end());
    
    int sum = 0, cnt = 0;
    for(auto cur : d){
        sum += cur;
        if(sum > budget)   break;
        cnt++;
    }
    return cnt;
}

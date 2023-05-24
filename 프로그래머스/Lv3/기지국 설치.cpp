#include <vector>
#include <cmath>

using namespace std;

int solution(int n, vector<int> stations, int w){
    int cnt = 0, prev = 1;
    for(auto st : stations){
        if(st - w > prev)
            cnt += ceil(static_cast<double>(st - prev - w) / static_cast<double>(w * 2 + 1));
        prev = st + w + 1;
    }
    if(prev <= n)           // 마지막 station이 마지막 아파트에 없을 경우
        cnt += ceil(static_cast<double>(n - prev + 1) / static_cast<double>(w * 2 + 1));
    return cnt;
}

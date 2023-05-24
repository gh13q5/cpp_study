#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    
    sort(rocks.begin(), rocks.end());
    
    int min = 0, max = distance;
    while(min <= max){
        int mid = (max + min) / 2;
        int del_cnt = 0, prev = 0;
        for(int i = 0; i < rocks.size(); i++){
            if(rocks[i] - prev < mid)   del_cnt++;
            else    prev = rocks[i];
        }
        if(distance - prev < mid)   del_cnt++;
        
        if(del_cnt <= n){
            min = mid + 1;
            answer = mid;
        }
        else    max = mid - 1;
    }
    
    return answer;
}

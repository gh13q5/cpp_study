#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    queue<int> q1, q2;
    long long sum_q1 = 0, sum_q2 = 0;
    
    for(int i = 0; i < queue1.size(); i++){
        q1.push(queue1[i]);     q2.push(queue2[i]);
        sum_q1 += queue1[i];    sum_q2 += queue2[i];     // queue에 넣고, 각 큐의 합 구하기
    }
    
    if(abs(sum_q1 - sum_q2) % 2 == 1)     return -1;
    
    int cnt = 0;
    while(!q1.empty() && !q2.empty()){
        if(cnt >= queue1.size() * 3)    return -1;
        if(sum_q1 == sum_q2)            return cnt;
        if(sum_q1 > sum_q2){
            sum_q1 -= q1.front();       sum_q2 += q1.front();
            q2.push(q1.front());        q1.pop();
        }
        else{
            sum_q2 -= q2.front();       sum_q1 += q2.front();
            q1.push(q2.front());        q2.pop();
        }
        cnt++;
    }
    
    return -1;
}

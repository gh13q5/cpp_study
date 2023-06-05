#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b){
	if(a[1] == b[1]){
        if(a[0] == b[0])    return a[2] < b[2];
            return a[0] < b[0];
    }
    return a[1] < b[1];
}

vector<long long> solution(vector<vector<int>> program) {
    sort(program.begin(), program.end(), cmp);      // cmp 기준 : 호출시간 - 우선순위 - 실행시간
    
    int idx = 0,    time = 0;
    vector<long long> answer(11, 0);
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> ready_pq;        // 대기 큐
    
    while(idx < program.size() || !ready_pq.empty()){
        while((idx < program.size()) && (program[idx][1] <= time)){
            ready_pq.push({program[idx][0], program[idx][1], program[idx][2]});
            idx++;
        }
        
        if(ready_pq.empty()){   // 전체 작업이 아직 안 끝났는데, 당장 작업할 수 있는 게 없을 때
            time = program[idx][1];
            continue;
        }
        
        answer[ready_pq.top()[0]] += (time - ready_pq.top()[1]);
        time += ready_pq.top()[2];
        ready_pq.pop();
    }
    answer[0] = time;
    return answer;
}

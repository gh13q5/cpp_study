#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;    
    for(int i = 0; i <= right - left; i++){
        int max_n = max((left + i) / n + 1, (left + i) % n + 1);
        answer.push_back(max_n);
    }
    return answer;
}

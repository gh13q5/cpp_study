#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    long long min = 1;
    long long max = (long long)times.back() * n;
    
    sort(times.begin(), times.end());

    while(min <= max){
        long long mid = (min + max) / 2;
        long long immigration = 0;
        for(int i = 0; i < times.size(); i++)
            immigration += (mid / times[i]);
        
        if(immigration >= n){
            max = mid - 1;
            answer = mid;
        }
        else if(immigration < n)    min = mid + 1;
    }
    
    return answer;
}

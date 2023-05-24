#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(int i = 0; i < numbers.size(); i++){
        if(numbers[i] % 2 == 0)     answer.push_back(numbers[i] + 1);
        else{
            int idx = 0;
            long long tmp = numbers[i];
            while(tmp != 0){
                if(tmp % 2 == 0)    break;
                idx++,  tmp /= 2;
            }
            answer.push_back(numbers[i] + pow(2, idx) - pow(2, idx - 1));
        }
    }
    return answer;
}

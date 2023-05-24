#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    set<int> sum_list;
    for(int i = 0; i < numbers.size() - 1; i++)
        for(int j = i + 1; j < numbers.size(); j++)
            sum_list.insert(numbers[i] + numbers[j]);
    
    vector<int> answer(sum_list.begin(), sum_list.end());
    return answer;
}

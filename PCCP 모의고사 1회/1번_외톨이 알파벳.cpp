#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string input_string) {
    string tmp = "";
    tmp += input_string[0];
    for(int i = 0; i < input_string.length() - 1; i++){
        if(input_string[i] == input_string[i + 1])  continue;
        tmp += input_string[i + 1];
    }
    
    sort(tmp.begin(), tmp.end());
    
    string answer = "";
    for(int i = 0; i < tmp.length(); i++)
        if(tmp[i] == tmp[i + 1] && answer.back() != tmp[i])    answer += tmp[i];
    if(answer == "")    return "N";
    return answer;
}

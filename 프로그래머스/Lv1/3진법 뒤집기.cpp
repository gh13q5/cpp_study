#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    string trit = "";
    while(n > 0)
        trit += to_string(n % 3),    n /= 3;
    
    int answer = 0;
    for(int i = trit.length() - 1; i >= 0; i--)
        answer += ((trit[i] - '0') * pow(3, trit.length() - i - 1));
    return answer;
}

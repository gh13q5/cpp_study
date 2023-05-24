#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int sum = 0;
    for(int i = left; i <= right; i++){
        int cnt = 0;
        for(int j = 1; j <= i / 2; j++)
            if(i % j == 0)  cnt++;
        (cnt + 1) % 2 == 0 ? (sum += i) : (sum -= i);       // 자기 자신도 약수에 포함하기 때문에 cnt + 1
    }
    return sum;
}

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int cnt = 0;
    int a_idx = 0, b_idx = 0;
    while(a_idx < A.size() && b_idx < B.size()){
        if(A[a_idx] < B[b_idx])
            cnt++,  a_idx++,    b_idx++;
        else        b_idx++;
    }
    return cnt;
}

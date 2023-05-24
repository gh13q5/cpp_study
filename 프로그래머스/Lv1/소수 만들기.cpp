#include <vector>
#include <algorithm>

using namespace std;

bool is_prime(int n){
    for(int i = 2; i < n; i++)
        if(n % i == 0)  return false;
    return true;
}

int solution(vector<int> nums) {
    sort(nums.begin(), nums.end());
    
    vector<bool> tmp(nums.size(), true);
    for(int i = 0; i < nums.size() - 3; i++)
        tmp[i] = false;

    int cnt = 0;
    do{
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
            if(tmp[i])  sum += nums[i];
        if(is_prime(sum))   cnt++;
    }while(next_permutation(tmp.begin(), tmp.end()));
    return cnt;
}

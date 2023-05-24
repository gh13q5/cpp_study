#include <string>
#include <vector>

using namespace std;

int deliver(int cap, vector<int> &list){
    int distance = 0;
    long long cnt = 0;
    while(cnt < cap && !list.empty()){
        if(distance == 0 && list.back() != 0)
            distance = list.size();
        cnt += list.back();
        if(cnt > cap)
            list[list.size() - 1] = cnt - cap;
        else    list.pop_back();
    }
    return distance;
}

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long distance = 0;
    
    while(!deliveries.empty() || !pickups.empty()){
        int distance_d = deliver(cap, deliveries);
        int distance_p = deliver(cap, pickups);
        distance += (distance_d > distance_p) ? ((long long)(distance_d * 2)) : (long long)(distance_p * 2);
    }
    
    return distance;
}

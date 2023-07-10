#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    unordered_map<string, int> revenue;
    for(int i = 0; i < enroll.size(); i++)
        revenue.insert({enroll[i], 0});
    
    unordered_map<string, string> refer_m;
    for(int i = 0; i < enroll.size(); i++)
        refer_m.insert({enroll[i], referral[i]});
    
    for(int i = 0; i < seller.size(); i++){
        int money = amount[i] * 100;
        string cur = seller[i];
        while(money > 0){
            revenue[cur] += (money - (money / 10));
            money /= 10;
            
            string next = refer_m[cur];
            if(next == "-") break;
            cur = next;
        }
    }
    
    vector<int> answer(enroll.size(), 0);
    for(int i = 0; i < enroll.size(); i++)
        answer[i] = revenue[enroll[i]];
    return answer;
}

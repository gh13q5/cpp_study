#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> s) {
    vector<string> answer;
    for(string cur : s){
        int cnt = 0;
        for(int i = 0; (cur.length() > 3) && (i < cur.length() - 2); i++){
            if(cur[i] == '1' && cur[i + 1] == '1' && cur[i + 2] == '0'){
                cur.erase(i, 3);
                i > 2 ? i -= 4 : i = -1;
                cnt++;
            }
        }
        for(int i = cur.length() - 1; i >= 0; i--){
            if(i == 0 || cur[i] == '0'){
                int idx = (cur[i] == '0') ? i + 1 : i;
                for(int j = 0; j < cnt; j++)
                    cur.insert(idx, "110");
                break;
            }
        }
        answer.push_back(cur);
    }
    return answer;
}

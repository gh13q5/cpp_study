#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    int cnt = 0,    zero_cnt = 0;
    string tmp = "";
    
    while(s != "1"){
        for(char c : s){
            if(c == '1')    tmp += '1';                 // 1) 0 제거
            else    zero_cnt++;
        }
        s = tmp,    tmp = "";
        
        int size = s.length();                          // 2) 길이 변환
        while(size > 0)
            tmp += to_string(size % 2),  size /= 2;
                
        s = "";
        for(int i = tmp.length() - 1; i >= 0; i--)
            s += tmp[i];
        tmp = "";
        
        cnt++;
    }
    
    return {cnt, zero_cnt};
}

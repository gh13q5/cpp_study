#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int cnt = 0;
    for(int i = 0; i < s.length(); i++){
        bool isRight = true;
        stack<char> st;
        for(char c : s){
            if(c == ')'){
                if(!st.empty() && st.top() == '(')  st.pop();
                else{   isRight = false;    break;  }
            }
            else if(c == ']'){
                if(!st.empty() && st.top() == '[')  st.pop();
                else{   isRight = false;    break;  }
            }
            else if(c == '}'){
                if(!st.empty() && st.top() == '{')  st.pop();
                else{   isRight = false;    break;  }
            }
            else    st.push(c);
        }
        if(isRight && st.empty())  cnt++;
        s += s[0];      s.erase(0, 1);
    }
    
    return cnt;
}

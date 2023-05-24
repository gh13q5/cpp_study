#include <string>
#include <vector>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    for(int i = 0; i < privacies.size(); i++){
        int year = stoi(privacies[i].substr(0, 4));
        int month = stoi(privacies[i].substr(5, 2));
        int day = stoi(privacies[i].substr(8, 2));
        char type = privacies[i][11];
        
        int term = 0;
        for(int j = 0; j < terms.size(); j++)
            if(terms[j][0] == type) term = stoi(terms[j].substr(2));
        
        year += (term / 12);
        month += (term % 12);
        if(month > 12){
            year++;
            month -= 12;
        }
        
        if(year < stoi(today.substr(0, 4))
          || (year == stoi(today.substr(0, 4)) && month < stoi(today.substr(5, 2)))
          || (year == stoi(today.substr(0, 4)) && month == stoi(today.substr(5, 2)) && day <= stoi(today.substr(8, 2))))
           answer.push_back(i + 1);
    }
    
    return answer;
}

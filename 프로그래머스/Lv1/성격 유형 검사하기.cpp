#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

void insert_map(unordered_map<char, int> &m){
    m.insert(make_pair('R', 0));    m.insert(make_pair('T', 0));
    m.insert(make_pair('C', 0));    m.insert(make_pair('F', 0));
    m.insert(make_pair('J', 0));    m.insert(make_pair('M', 0));
    m.insert(make_pair('A', 0));    m.insert(make_pair('N', 0));
}

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    unordered_map<char, int> type;     // R, T, C, F, J, M, A, N
    
    insert_map(type);
    
    for(int i = 0; i < survey.size(); i++){
        if(choices[i] < 4)          type[survey[i][0]] += (4 - choices[i]);
        else if(choices[i] > 4)     type[survey[i][1]] += (choices[i] - 4);
    }
    
    if(type['R'] >= type['T'])  answer += 'R';
    else    answer += 'T';
    if(type['C'] >= type['F'])  answer += 'C';
    else    answer += 'F';
    if(type['J'] >= type['M'])  answer += 'J';
    else    answer += 'M';
    if(type['A'] >= type['N'])  answer += 'A';
    else    answer += 'N';
    
    return answer;
}

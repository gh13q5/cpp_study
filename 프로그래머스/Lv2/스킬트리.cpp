#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for(auto t : skill_trees){
        string include_skill = "";
        for(auto c : t)
            if(skill.find(c) != string::npos)   include_skill += c;
        if(skill.find(include_skill) == 0)  answer++;
    }
    return answer;
}

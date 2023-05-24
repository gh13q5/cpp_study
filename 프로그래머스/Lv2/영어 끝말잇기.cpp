#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    string pre = words[0];
    vector<string> said;
    said.push_back(pre);
    
    for(int i = 1; i < words.size(); i++){
        if(pre.back() != words[i].front())  return {i % n + 1, i / n + 1};
        for(int j = 0; j < said.size(); j++)
            if(words[i] == said[j])     return {i % n + 1, i / n + 1};
        pre = words[i];
        said.push_back(pre);
    }
    return {0, 0};
}

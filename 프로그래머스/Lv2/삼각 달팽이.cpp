#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    char pos = 'l';
    int size = n * (n + 1) / 2;
    int i = 1, x = 0, y = 0;
    vector<vector<int>> triangle(n + 1, vector<int>(n + 1, 0));
    
    while(i <= size){
        int max_num = i + n - 1;
        switch(pos){
            case 'l':
                while(i <= max_num)
                    triangle[y++][x] = i++;
                pos = 'b', y--;
                break;
            case 'b':
                while(i <= max_num - 1)
                    triangle[y][++x] = i++;
                pos = 'r';
                break;
            case 'r':
                while(i <= max_num - 2)
                    triangle[--y][--x] = i++;
                pos = 'l', n -= 3, y++;
                break;
        }
    }
    
    vector<int> answer;
    for(auto r : triangle)
        for(auto c : r)
            if(c != 0)  answer.push_back(c);
    return answer;
}

#include <string>
#include <vector>

using namespace std;

int zero_cnt = 0,   one_cnt = 0;

void quad_tree(int size, int start_x, int start_y, const vector<vector<int>> &arr){
    int start_data = arr[start_x][start_y];
    if(size == 1){
        (start_data == 0) ? zero_cnt++ : one_cnt++;
        return;
    }
    
    bool isComb = true;         // 하나로 합쳐지는가?
    for(int i = start_x; i < start_x + size; i++){
        for(int j = start_y; j < start_y + size; j++)
            if(arr[i][j] != start_data){
                isComb = false;
                break;
            }
        if(!isComb)     break;
    }
    
    if(isComb){
        (start_data == 0) ? zero_cnt++ : one_cnt++;
        return;
    }
    
    quad_tree(size / 2, start_x, start_y, arr);
    quad_tree(size / 2, start_x, start_y + (size / 2), arr);
    quad_tree(size / 2, start_x + (size / 2), start_y, arr);
    quad_tree(size / 2, start_x + (size / 2), start_y + (size / 2), arr);       // 왼위 - 오위 - 왼아 - 오아
}

vector<int> solution(vector<vector<int>> arr) {
    quad_tree(arr.size(), 0, 0, arr);
    return {zero_cnt, one_cnt};
}

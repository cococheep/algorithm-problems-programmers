// 등굣길
// https://programmers.co.kr/learn/courses/30/lessons/42898

#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    int map[101][101] = {0, };
    int MAX = 1000000007;
    
    for(auto i: puddles){
        map[i[0]][i[1]] = -1;
    }

    int i = 1;
    while(map[i][1] == 0 && i <= m){
        map[i++][1] = 1;
    }
    int j = 2;
    while(map[1][j] == 0 && j <= n){
        map[1][j++] = 1;
    }
    
    for(auto i: puddles){
        if(i[0] == 1 || i[1] == 1){
            map[i[0]][i[1]] = 0;
        }
    }
    
    for(int y = 2; y <= n; y++){
        for(int x = 2; x <= m; x++){
            if(map[x][y] == -1){
                map[x][y] = 0;
            }
            else{
                map[x][y] = (map[x][y - 1] + map[x - 1][y]) % MAX;
            }
        }
    }    
    
    answer = map[m][n];    
    return answer;
}
// 네트워크
// https://programmers.co.kr/learn/courses/30/lessons/43162

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> searched(n, false);
    queue<int> network;

    for(int i = 0 ; i < n; i++){
        if(!searched[i]){
            answer++;
            network.push(i);
            searched[i] = true;
            while(!network.empty()){
                int cur = network.front();
                for(int i = 0; i < n; i++){
                    if(computers[cur][i] && !searched[i]){
                        network.push(i);
                        searched[i] = true;
                    }
                }
                network.pop();
            }
        }
    }
    return answer;
}
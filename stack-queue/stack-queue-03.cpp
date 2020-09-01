// 다리를 지나는 트럭
// https://programmers.co.kr/learn/courses/30/lessons/42583

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> onBridge;
    
    int total_weight = 0;    
    int idx = 0;
    
    while(idx < truck_weights.size()){
        if(onBridge.size() == bridge_length){
            total_weight -= onBridge.front();
            onBridge.pop();
        }        
        
        if(total_weight + truck_weights[idx] <= weight){
            total_weight += truck_weights[idx];
            onBridge.push(truck_weights[idx++]);
        }
        else{
            onBridge.push(0);
        }
        answer++;
    }
    
    answer += bridge_length; // 마지막 트럭이 건너는 시간

    return answer;
}
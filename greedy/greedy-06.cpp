// 단속카메라
// https://programmers.co.kr/learn/courses/30/lessons/42884

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b){
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 1;
    
    sort(routes.begin(), routes.end(), compare);
    int camera = routes[0][1];
    
    for(int i = 0; i < routes.size(); i++){
        if(routes[i][0] > camera){
            camera = routes[i][1];
            answer++;
        }
    }

    return answer;
}
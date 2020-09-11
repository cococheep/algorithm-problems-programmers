// 정수 삼각형
// https://programmers.co.kr/learn/courses/30/lessons/43105

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    queue<int> dp;
    dp.push(triangle[0][0]);
    
    for(int i = 1; i < triangle.size(); i++){
        dp.push(dp.front() + triangle[i][0]);
        for(int j = 1; j < triangle[i].size() - 1; j++){
            int left = dp.front();
            dp.pop();
            int right = dp.front();
            dp.push(triangle[i][j] + max(left, right));
        }
        dp.push(dp.front() + triangle[i].back());
        dp.pop();
    }
    
    int maxSum = 0;
    while(!dp.empty()){
        if(dp.front() > maxSum) maxSum = dp.front();
        dp.pop();
    }
    answer = maxSum;
    
    return answer;
}
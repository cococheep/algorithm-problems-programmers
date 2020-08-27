// https://programmers.co.kr/learn/courses/30/lessons/42586?language=cpp

#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> remain;

    int len = progresses.size();
    for(int i = 0; i < len; i++){
        int r  = (100 - progresses[i]) / speeds[i];
        if((100 - progresses[i]) % speeds[i]) r += 1;
        remain.push(r);
    }
    
    while(!remain.empty()){
        int cur = remain.front();
        int releaseNum = 0;
        while(remain.front() <= cur && !remain.empty()){
            remain.pop();
            releaseNum++;            
        }
        answer.push_back(releaseNum);
    }
    
    return answer;
}
// 디스크 컨트롤러
// https://programmers.co.kr/learn/courses/30/lessons/42627

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool byRequest(vector<int> a, vector<int> b){
    return a[0] < b[0];
}

bool byProcess(vector<int> a, vector<int> b){
    return a[1] > b[1];
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    vector<vector<int>> ready;
    int done = 0;
    int time = 0;
    int cur = 0;

    sort(jobs.begin(), jobs.end(), byRequest);
    
    while(done < jobs.size()){
        if(ready.empty()){
            time = time < jobs[cur][0] ? jobs[cur][0] : time;
        }
        while(cur < jobs.size() && jobs[cur][0] <= time){
            ready.push_back(jobs[cur]);
            push_heap(ready.begin(), ready.end(), byProcess);
            cur++;
        }        
        
        time += ready.front()[1];
        answer += time - ready.front()[0];
        
        pop_heap(ready.begin(), ready.end(), byProcess);
        ready.pop_back();
        done++;
    }
    
    answer /= jobs.size();
    return answer;
}
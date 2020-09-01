// 더 맵게
// https://programmers.co.kr/learn/courses/30/lessons/42626

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool minSort(int a, int b){
    return a > b;
}

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    make_heap(scoville.begin(), scoville.end(), minSort);
    
    while(scoville.size() > 1){
        if(scoville[0] >= K) return answer;

        int element[2];
        for(int i = 0; i < 2; i++){
            pop_heap(scoville.begin(), scoville.end(), minSort);
            element[i] = scoville.back();
            scoville.pop_back();            
        }
        
        scoville.push_back(element[0] + 2 * element[1]);
        push_heap(scoville.begin(), scoville.end(), minSort);
        answer++;        
    }
    
    answer = scoville[0] >= K ? answer : -1;
    
    return answer;
}
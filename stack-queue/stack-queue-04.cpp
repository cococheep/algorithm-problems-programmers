// https://programmers.co.kr/learn/courses/30/lessons/42587

#include <string>
#include <vector>
#include <queue>

using namespace std;

int numList [10] = {0, };

bool isHighest(int priority){
    for(int i = priority + 1; i < 10; i++){
        if(numList[i] > 0) return false;
    }
    return true;
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<int> printQueue;
    
    int len = priorities.size();
    for(int i = 0; i < len; i++){
        printQueue.push(i);
        numList[priorities[i]]++;
    }
    
    int print = -1;
    while(print != location){
        while(!isHighest(priorities[printQueue.front()])){
            int tmp = printQueue.front();
            printQueue.pop();
            printQueue.push(tmp);
        }
        
        print = printQueue.front();
        numList[priorities[print]]--;
        printQueue.pop();
        answer++;
    }
    
    return answer;
}

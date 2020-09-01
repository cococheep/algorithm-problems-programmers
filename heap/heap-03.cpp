// 이중우선순위큐
// https://programmers.co.kr/learn/courses/30/lessons/42628

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool minHeapCompare(int a, int b){
    return a > b;
}

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<int> maxHeap;
    vector<int> minHeap;
    
    int op = 0;
    while(op < operations.size()){
        switch(operations[op][0]){
            case 'I':{
                int num = stoi(operations[op].substr(2));
                maxHeap.push_back(num);
                push_heap(maxHeap.begin(), maxHeap.end());
                minHeap.push_back(num);
                push_heap(minHeap.begin(), minHeap.end(), minHeapCompare);
                break;                
            }
                
            case 'D':{
                if(maxHeap.empty())
                    break;
                if(operations[op][2] == '1'){
                    pop_heap(maxHeap.begin(), maxHeap.end());
                    maxHeap.pop_back();
                    minHeap = maxHeap;
                    make_heap(minHeap.begin(), minHeap.end(), minHeapCompare);
                }
                else{
                    pop_heap(minHeap.begin(), minHeap.end(), minHeapCompare);
                    minHeap.pop_back();
                    maxHeap = minHeap;
                    make_heap(maxHeap.begin(), maxHeap.end());
                }
                break;                
            }
        }
        op++;
    }
    
    if(maxHeap.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(maxHeap.front());
        answer.push_back(minHeap.front());
    }
    
    return answer;
}
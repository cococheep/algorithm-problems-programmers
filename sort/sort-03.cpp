// H-Index
// https://programmers.co.kr/learn/courses/30/lessons/42747

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool mySort(int a, int b){
    return a > b;
}

int solution(vector<int> citations) {
    int answer = 0;

    sort(citations.begin(), citations.end(), mySort);
    int max_h = citations.size();
    while(citations[max_h - 1] < max_h){
        max_h -= 1;
    }
    
    answer = max_h;
    return answer;
}
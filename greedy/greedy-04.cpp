// 구명보트
// https://programmers.co.kr/learn/courses/30/lessons/42885

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool larger(int a, int b){
    return a > b;
}

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end(), larger);

    int start = 0;
    int end = people.size() - 1;
    while(start <= end){
        if(people[start] + people[end] <= limit){
            end--;
        }
        start++;
        answer++;
    }
        
    return answer;
}
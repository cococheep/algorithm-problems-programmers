// 체육복
// https://programmers.co.kr/learn/courses/30/lessons/42862

#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    vector<int> student (n + 2, 1);
    student[0] = -1;
    student[n + 1] = -1;

    for(int i = 0; i < lost.size(); i++){
        student[lost[i]]--;
        answer--;
    }
    for(int i = 0; i < reserve.size(); i++){
        student[reserve[i]]++;
    }

    for(int i = 0; i < reserve.size(); i++){
        if(student[reserve[i]] == 1){
            answer++;
        }
        else if(student[reserve[i]] == 2){
            if(student[reserve[i] - 1] == 0){
                student[reserve[i] - 1]++;
                student[reserve[i]]--;
                answer++;
            }
            else if(student[reserve[i] + 1] == 0){
                student[reserve[i] + 1]++;
                student[reserve[i]]--;
                answer++;
            }
        }
    }
    
    return answer;
}
// 완주하지 못한 선수
// https://programmers.co.kr/learn/courses/30/lessons/42576

#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_set<string> runner;
    
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    for(int i = 0; i < completion.size(); i++){
        if(participant[i] != completion[i])
            return participant[i];
    }
        
    return participant[participant.size() - 1];
}
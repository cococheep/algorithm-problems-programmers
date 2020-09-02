// 위장
// https://programmers.co.kr/learn/courses/30/lessons/42578

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    unordered_map<string, int> kinds;
    for(int i = 0; i < clothes.size(); i++){
        kinds[clothes[i][1]]++;
    }

    for(auto& k: kinds){
        answer *= (k.second + 1);
    }
    answer -= 1;
    
    return answer;
}
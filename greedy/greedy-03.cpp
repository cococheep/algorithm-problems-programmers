// 조이스틱
// https://programmers.co.kr/learn/courses/30/lessons/42860

#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    int len = name.size();
    
    vector<int> turn;
    for(int i = 0; i < len; i++){
        int n = name[i] - 'A';
        n = n > 13 ? 26 - n : n;
        turn.push_back(n);
        answer += n;
    }
    turn.push_back(-1);

    int maxZero = 0;
    int idx = 0;
    int start = 0;
    int end = 0;
    while(idx < len){
        if(turn[idx] == 0){
            int temp = idx;
            while(turn[++idx] == 0){}
            if(idx - temp > maxZero){
                maxZero = idx - temp;
                start = temp;
                end = idx;
            }
        }
        idx++;
    }
    if(start == end){
        return answer + len - 1;
    }

    int path = maxZero < start - 1 ? maxZero : (start - 1 < len - end ? start - 1 : len - end); 
    answer = answer + (len - 1) - maxZero + path;        

    return answer;
}

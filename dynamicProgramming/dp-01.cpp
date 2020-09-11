// N으로 표현
// https://programmers.co.kr/learn/courses/30/lessons/42895

#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int N, int number) {
    int answer = 0;
    vector<set<int>> used;
    
    int NN = 0;
    for(int i = 0; i < 9; i++){
        if(NN == number) return i;
        set<int> temp;
        temp.insert(NN);
        used.push_back(temp);
        NN = NN * 10 + N;
    }    
    
    for(int i = 1; i < 9; i++){
        for(int j = 1; j < i; j++){
            for(auto n1: used[j]){
                for(auto n2: used[i - j]){
                    used[i].insert(n1 + n2);
                    used[i].insert(n1 - n2);
                    used[i].insert(n1 * n2);
                    if(n2) used[i].insert(n1 / n2);
                }
            }
        }
        for(auto n: used[i]){
            if(n == number) return i;
        }
    }
        
    answer = -1;
    return answer;
}
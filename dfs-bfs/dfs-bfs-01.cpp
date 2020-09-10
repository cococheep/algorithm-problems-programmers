// 타겟 넘버
// https://programmers.co.kr/learn/courses/30/lessons/43165

#include <string>
#include <vector>

using namespace std;

vector<int> num;
int t;
int maxD;

int dfs(int res, int depth){
    if(depth == maxD - 1){
        return res == t ? 1 : 0;
    }
    else{
        return dfs(res + num[depth + 1], depth + 1) + dfs(res - num[depth + 1], depth + 1);
    }
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    num = numbers;
    t = target;
    maxD = numbers.size();
    
    answer = dfs(0, -1);

    return answer;
}
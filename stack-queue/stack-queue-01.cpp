// 주식 가격
// https://programmers.co.kr/learn/courses/30/lessons/42584

#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;

    int len = prices.size();
    for(int cur = 0; cur < len - 1; cur++){
        int next = cur;
        while(prices[next] >= prices[cur] && next != len - 1){
            next++;
        }
        answer.push_back(next - cur);
    }
    answer.push_back(0);

    return answer;
}
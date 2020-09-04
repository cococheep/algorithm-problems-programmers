// 카펫
// https://programmers.co.kr/learn/courses/30/lessons/42842

#include <string>
#include <vector>

using namespace std;
    
vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    for(int i = 1; i * i <= yellow; i++){
        if(yellow % i == 0){
            int n = yellow / i;
            if(2 * (n + 2) + 2 * i == brown){
                return vector<int> {n + 2, i + 2};
            }
            if(2 * (i + 2) + 2 * n == brown){
                return vector<int> {i + 2, n + 2};
            }            
        }
    }

    return answer;
}
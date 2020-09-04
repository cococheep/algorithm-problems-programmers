// 소수 찾기
// https://programmers.co.kr/learn/courses/30/lessons/42839

#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool isPrime(int n){
    if(n < 2) return false;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return false;        
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<string> element;
    unordered_set<int> possible;

    for(int i = 0; i < numbers.size(); i++){
        element.push_back(numbers.substr(i, 1));
    }    
    sort(element.begin(), element.end());
    
    do{
        string p = "";
        for(int i = 0; i < element.size(); i++){
            p += element[i];
        }
        for(int i = 0; i < element.size(); i++){
            int n = stoi(p.substr(i));
            if(possible.find(n) == possible.end()){
                possible.insert(n);
                if(isPrime(n)){
                    answer++;
                }
            }
        }
    }while(next_permutation(element.begin(), element.end()));
    return answer;
        
}
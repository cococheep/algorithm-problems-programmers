// 가장 큰 수
// https://programmers.co.kr/learn/courses/30/lessons/42746

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int log10(int n){
    if(n < 10) return 1;
    else if(n < 100) return 2;
    else if(n < 1000) return 3;
    else return 4;
}

int myPow(int n, int p){
    for(int i = 0; i < p; i++){
        n *= 10;
    }
    return n;
}

bool mySort(int a, int b){
    int a_len = log10(a);
    int b_len = log10(b);
    
    int firstComb = myPow(a, (b_len)) + b;
    int secondComb = myPow(b, (a_len)) + a;
    
    return firstComb > secondComb;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    sort(numbers.begin(), numbers.end(), mySort);
    
    bool isAllZero = true;
    for(int i = 0; i < numbers.size(); i++){
        if(numbers[i] != 0) isAllZero = false;
        answer += to_string(numbers[i]);
    }
    
    if(isAllZero) answer = "0";
    return answer;
}
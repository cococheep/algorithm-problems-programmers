// 전화번호 목록
// https://programmers.co.kr/learn/courses/30/lessons/42577

#include <string>
#include <vector>
#include <set>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;    
    
    vector<int> isSizeExist(21, 0);
    for(int i = 0; i < phone_book.size(); i++){
        isSizeExist[phone_book[i].size()]++;
    }
    set<string> original (phone_book.begin(), phone_book.end());

    set<string> prefix;
    for(int i = 0; i < phone_book.size(); i++){
        for(int len = 1; len <= phone_book[i].size(); len++){
            if(isSizeExist[len]){
                string sub = phone_book[i].substr(0, len);
                if(original.find(sub) != original.end() && prefix.find(sub) != prefix.end()){
                    return false;
                }
                prefix.insert(sub);
            }            
        }       
    }
    
    return answer;
}
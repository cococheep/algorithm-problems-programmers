// 여행경로
// https://programmers.co.kr/learn/courses/30/lessons/43164

#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int len;
map<string, vector<int>> dest;
vector<bool> used;
vector<vector<string>> t;
vector<string> complete;

bool dfs(vector<string> cur, int depth){
    if(depth == len + 1){
        complete = cur;
        return true;
    }
    else{
        string currentCity = cur.back();
        for(auto i: dest[currentCity]){
            if(!used[i]){
                cur.push_back(t[i][1]);
                used[i] = true;
                if(dfs(cur, depth + 1)) return true;
                cur.pop_back();
                used[i] = false;
            }
        }
        return false;
    }
}

bool compare(vector<string> a, vector<string> b){
    if(a[0] < b[0]) return true;
    else if(a[0] == b[0]){
        if(a[1] < b[1]) return true;
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    sort(tickets.begin(), tickets.end(), compare);
    
    for(int i = 0; i < tickets.size(); i++){
        dest[tickets[i][0]].push_back(i);
        used.push_back(false);
    }
    
    len = tickets.size();
    t = tickets;
    
    for(auto i: dest["ICN"]){
        vector<string> cur = {"ICN"};
        if(dfs(cur, 1)) return complete;
    }
    
    return answer;
}
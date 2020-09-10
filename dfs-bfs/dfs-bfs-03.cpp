// 단어 변환
// https://programmers.co.kr/learn/courses/30/lessons/43163

#include <string>
#include <vector>

using namespace std;

vector<string> w;
string t;
vector<vector<int>> connect;
int minDepth = 9999;

int isConnected(string a, string b){
    int diff = 0;
    int idx;
    for(int i = 0; i < a.size(); i++){
        if(a[i] != b[i]){
            diff++;
            idx = i;
        }
    }
    return diff == 1 ? idx : -1;
}

void dfs(int cur, int pos, int depth){
    if(depth < minDepth){
        if(w[cur] == t){
            minDepth = depth;
        }
        else{
            for(int i = 0; i < connect[cur].size(); i++){
                if(connect[cur][i] != pos && connect[cur][i] != -1){
                    dfs(i, connect[cur][i], depth + 1);
                }
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    bool isTarget = false;
    for(auto i: words){
        if(i == target) isTarget = true;
    }
    if(!isTarget) return 0;
    
    for(int i = 0; i < words.size(); i++){
        vector<int> node;
        for(int j = 0; j < words.size(); j++){
            node.push_back(isConnected(words[i], words[j]));
        }
        connect.push_back(node);
    }
    
    w = words;
    t = target;
    for(int i = 0; i < words.size(); i++){
        int pos = isConnected(begin, words[i]);
        if(pos != -1){
            dfs(i, pos, 1);
        }
    }
    answer = minDepth;    
    return answer;
}
// 섬 연결하기
// https://programmers.co.kr/learn/courses/30/lessons/42861
// Kruskal Algorithm reference: https://muang-kim.tistory.com/140

#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<int, int> parent;
map<int, int> nodeRank;

int findParent(int node){
    if(parent[node] != node){
        parent[node] = findParent(parent[node]);
    }
    return parent[node];
}

void unionSet(int node1, int node2){
    int root1 = parent[node1];
    int root2 = parent[node2];
    
    if(nodeRank[root1] > nodeRank[root2]){
        parent[root2] = root1;
    }
    else{
        parent[root1] = root2;
        if(nodeRank[root1] == nodeRank[root2]){
            nodeRank[root2]++;
        }
    }
}

bool lessWeight(vector<int> a, vector<int> b){
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    for(int i = 0; i < n; i++){
        parent[i] = i;
        nodeRank[i] = 0;
    }
    
    sort(costs.begin(), costs.end(), lessWeight);

    int edge = 0;
    for(int i = 0; edge < n - 1; i++){
        if(findParent(costs[i][0]) != findParent(costs[i][1])){
            unionSet(costs[i][0], costs[i][1]);
            edge++;
            answer += costs[i][2];
        }
    }
    
    return answer;
}
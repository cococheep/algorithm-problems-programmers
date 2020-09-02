// 베스트앨범
// https://programmers.co.kr/learn/courses/30/lessons/42579

#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool sortByPlays(pair<int, int> a, pair<int, int> b){
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> totalSum;
    map<string, vector<pair<int, int>>> idxMap;

    for(int i = 0; i < genres.size(); i++){
      totalSum[genres[i]] += -(plays[i]);
      idxMap[genres[i]].push_back(make_pair(i, plays[i]));
    }
    
    map<int, string> sortedSum;
    for(auto sum: totalSum){
        sortedSum[sum.second] = sum.first;
    }

    for(auto it: sortedSum){
        vector<pair<int, int>> current = idxMap[it.second];
        sort(current.begin(), current.end(), sortByPlays);
        answer.push_back(current[0].first);
        if(current.size() > 1){
            answer.push_back(current[1].first);
        }
    }

    return answer;
}
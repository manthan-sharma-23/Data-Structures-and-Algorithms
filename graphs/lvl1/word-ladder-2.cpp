#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// by making adjancy list and then performing DFS
class Solution2 {

public:
  void dfs(string begin, string end,
           unordered_map<string, unordered_set<string>> adj,
           vector<string> &path, vector<vector<string>> &ans) {

    path.push_back(begin);
    if (begin == end) {
      ans.push_back(path);
      path.pop_back();

      return;
    }
    for (auto i : adj[begin]) {
      dfs(i, end, adj, path, ans);
    }

    path.pop_back();
  }

  vector<vector<string>> findLadders(string beginWord, string endWord,
                                     vector<string> &wordList) {

    queue<string> q;
    unordered_map<string, int> graph;
    unordered_set<string> dict(wordList.begin(), wordList.end());
    unordered_map<string, unordered_set<string>> adj;
    vector<vector<string>> v;

    graph[beginWord] = 0;
    q.push(beginWord);

    while (!q.empty()) {
      string curr = q.front();

      q.pop();

      string temp = curr;

      for (int i = 0; i < curr.size(); i++) {

        for (char ch = 'a'; ch <= 'z'; ch++) {

          if (temp[i] == ch)
            continue;

          temp[i] = ch;

          if (dict.count(temp)) {
            if (!graph.count(temp)) {
              graph[temp] = graph[curr] + 1;
              q.push(temp);
              adj[curr].insert(temp);

            } else if (graph[curr] + 1 == graph[temp]) {
              adj[curr].insert(temp);
            }
          }
        }
        temp[i] = curr[i];
      }
    }

    vector<string> path;
    dfs(beginWord, endWord, adj, path, v);

    return v;
  }
};

// LEVEL BY LEVEL BFS ON ARRAY DS
class Solution {
public:
  vector<vector<string>> findLadders(string beginWord, string endWord,
                                     vector<string> &wordList) {
    unordered_set<string> dict(wordList.begin(), wordList.end());
    queue<vector<string>> Q;

    vector<vector<string>> ans;

    Q.push({beginWord});

    vector<string> usedOnLevel;
    int level = 0;
    usedOnLevel.push_back(beginWord);

    while (!Q.empty()) {
      vector<string> vec = Q.front();
      Q.pop();
      if (vec.size() > level) {
        level++;
        for (auto it : vec) {
          dict.erase(it);
        }
      }

      string word = vec.back();

      if (word == endWord) {
        if (ans.size() == 0) {
          ans.push_back(vec);
        } else if (ans[0].size() == vec.size()) {
          ans.push_back(vec);
        }
      }

      for (int i = 0; word.length(); i++) {
        char original = word[i];
        for (char ch = 'a'; ch <= 'z'; ch++) {
          word[i] = ch;
          if (dict.count(word)) {
            vec.push_back(word);
            Q.push(vec);
            usedOnLevel.push_back(word);
            vec.pop_back();
          }
        }
      }
    }
  }
};

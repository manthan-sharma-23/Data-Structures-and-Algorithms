#include <bits/stdc++.h>

using namespace std;

class TrieNode {
public:
  bool endOfWord;
  string word;
  vector<TrieNode *> children;
  TrieNode() {
    endOfWord = false;
    word = "";
    children = vector<TrieNode *>(26, nullptr);
  }
};

class Solution {
public:
  vector<string> result;
  const vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

  int m, n;
  void insertInTrie(TrieNode *root, string word) {
    TrieNode *crawler = root;

    for (const char &ch : word) {
      if (crawler->children[ch - 'a'] == nullptr) {
        crawler->children[ch - 'a'] = new TrieNode();
      }

      crawler = crawler->children[ch - 'a'];
    }

    crawler->endOfWord = true;
    crawler->word = word;
  }
  bool isValid(int r, int c) { return r >= 0 && c >= 0 && r < m && c < n; }

  void dfs(TrieNode *root, int i, int j, vector<vector<char>> &board) {
    if (!isValid(i, j))
      return;

    if (board[i][j] == '$' || root->children[board[i][j] - 'a'] == nullptr)
      return;

    root = root->children[board[i][j] - 'a'];

    if (root->endOfWord) {
      result.push_back(root->word);
      root->endOfWord = false;
    }

    char temp = board[i][j];
    board[i][j] = '$';

    for (auto &dir : directions) {
      int ni = i + dir.first;
      int nj = j + dir.second;

      dfs(root, ni, nj, board);
    }

    board[i][j] = temp;
  }

  vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {

    m = board.size();
    n = board[0].size();

    TrieNode *root = new TrieNode();

    for (const string &word : words) {
      insertInTrie(root, word);
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        char ch = board[i][j];

        if (root->children[ch - 'a'] != nullptr) {
          dfs(root, i, j, board);
        }
      }
    }

    return result;
  }
};
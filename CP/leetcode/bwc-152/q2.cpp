#include <string>
#include <vector>

using namespace std;

class Spreadsheet {
public:
  vector<vector<int>> sheet;

  int charToInt(char A) { return A - 'A'; }

  pair<int, int> parseCell(string cell) {

    int col = charToInt(cell[0]);
    int row = stoi(cell.substr(1));

    return {row, col};
  }

  int parseExp(string exp) {

    if (exp[0] >= 'A' && exp[0] <= 'Z') {
      auto [row, col] = parseCell(exp);
      return sheet[row][col];
    } else {
      return stoi(exp);
    }
  }

  Spreadsheet(int rows) { sheet.resize(rows + 1, vector<int>(26, 0)); }

  void setCell(string cell, int value) {
    auto [row, col] = parseCell(cell);
    sheet[row][col] = value;
  }

  void resetCell(string cell) {
    auto [row, col] = parseCell(cell);
    sheet[row][col] = 0;
  }

  int getValue(string formula) {
    int nf = formula.length();
    int diversion = formula.find('+');

    if (diversion == string::npos)
      return -1;

    string exp1 = formula.substr(1, diversion - 1);
    string exp2 = formula.substr(diversion + 1);

    return parseExp(exp1) + parseExp(exp2);
  }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
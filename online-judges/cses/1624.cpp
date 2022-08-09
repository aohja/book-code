/**
 * Author:  Aadi Ohja
 * Created: 06/08/2022 22:22:12
 * Problem: Chessboard and Queens
**/
#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using ll = long long;

#ifdef LOCAL
#include "ddebug.h"
#else
#define debug(...) 42
#endif

std::vector<std::string> board(8);

bool check(int x, int y, std::vector<std::string>& b) {
  if (board[x][y] == '*') {
    return false;
  }
  int i = 0;
  while (x - i >= 0) {
    if (b[x - i][y] == 'Q') {
      return false;
    }
    i++;
  }
  i = 0;
  while (x + i < 8 && y + i < 8) {
    if (b[x + i][y + i] == 'Q') {
      return false;
    }
    i++;
  }
  i = 0;
  while (x - i >= 0 && y + i < 8) {
    if (b[x - i][y + i] == 'Q') {
      return false;
    }
    i++;
  }
  i = 0;
  while (x + i < 8 && y - i >= 0) {
    if (b[x + i][y - i] == 'Q') {
      return false;
    }
    i++;
  }
  i = 0;
  while (x - i >= 0 && y - i >= 0) {
    if (b[x - i][y - i] == 'Q') {
      return false;
    }
    i++;
  }
  return true;
}

int rec(int cnt, std::vector<std::string> b) {
  if (cnt == 0) {
    return 1;
  }
  int ans = 0;
  for (int i = 0; i < 8; i++) {
    std::vector<std::string> cpy = std::vector<std::string>(b);
    if (check(8 - cnt, i, cpy)) {
      cpy[8 - cnt][i] = 'Q';
      ans += rec(cnt - 1, cpy);    
    }
  }
  return ans;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  for (int i = 0; i < 8; i++) {
    std::cin >> board[i];
  }
  std::cout << rec(8, board)  << "\n";
  return 0;
}

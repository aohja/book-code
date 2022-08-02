/**
 * Author:  Aadi Ohja
 * Created: 30/07/2022 20:40:38
 * Problem: Mowing the Field (Bronze) 
**/
#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using ll = long long;

#ifdef LOCAL
#include "ddebug.h"
#endif

template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

int N;
int grid[2010][2010];

int main() {
    read(N);
    int sx = 1005, sy = 1005;
    for (int i = 0; i < 2010; i++) {
        for (int j = 0; j < 2010; j++) {
            grid[i][j] = -1;
        }
    }
    int ans = 1e9;
    grid[sx][sy] = 0;
    int time = 1;
    for (int i = 1; i <= N; i++) {
        char dir; int delta;
        scanf("%c", &dir);
        read(delta);
        if (dir == 'N') {
            for (int y = sy + 1; y <= sy + delta; y++) {
                if (grid[sx][y] != -1) {
                    ans = std::min(ans, time - grid[sx][y]);
                }
                grid[sx][y] = time;
                time++;
            }
            sy += delta;
        } else if (dir == 'E') {
            for (int x = sx - 1; x >= sx - delta; --x) {
                if (grid[x][sy] != -1) {
                    ans = std::min(ans, time - grid[x][sy]);
                }
                grid[x][sy] = time;
                time++;
            }
            sx -= delta;
        } else if (dir == 'S') {
            for (int y = sy - 1; y >= sy - delta; --y) {
                if (grid[sx][y] != -1) {
                    ans = std::min(ans, time - grid[sx][y]);
                }
                grid[sx][y] = time;
                time++;
            }
            sy -= delta;
        } else {
            for (int x = sx + 1; x <= sx + delta; ++x) {
                if (grid[x][sy] != -1) {
                    ans = std::min(ans, time - grid[x][sy]);
                }
                grid[x][sy] = time;
                time++;
            }
            sx += delta;
        }
    }
    if (ans == 1e9) {
        ans = -1;
    }
    print(ans, '\n');
    return 0;
}

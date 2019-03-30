#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<bitset>
using namespace std;
const int mx = 401;

int grid[mx][mx];
int vis[mx][mx];
int n;

bool safe(int i, int j) {
    return (i<n && i>=0) && (j<n && j>=0) && (grid[i][j]==1);
}

bool kill(int i, int j) {
    if (vis[i][j] == 1) return false;
    if (!safe(i, j)) return false;
    if (i == (n-1)) return true;
    vis[i][j] = 1;
    if (kill(i-1, j-1)) return true;
    if (kill(i-1, j)) return true;
    if (kill(i, j-1)) return true;
    if (kill(i, j+1)) return true;
    if (kill(i+1, j+1)) return true;
    if (kill(i+1, j)) return true;
    return false;
}


bool solve() {
    memset(grid, -1, sizeof grid);
    memset(vis, -1, sizeof vis);
    string s;
    // cout << " solving\n";
    for (int i=0; i<n; i++) {
        cin >> s;
        for (int j=0; j<n; j++) {
            grid[i][j] = (s[j]=='b' ? 1 : 0);
        }
    }
    for (int i=0; i<n; i++) {
        if (kill(0, i)) {
            return true;
        }
    }
    return false;
}

int main() {
    // int t,
    int cnt=1;;
    cin >> n;
    while (n != 0) {
        cout << cnt << " ";
        if (solve()) {
            cout << "B\n";
        } else {
            cout << "W\n";
        }
        cnt++;
        cin >> n;
    } 
}
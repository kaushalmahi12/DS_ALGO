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

void kill(int i, int j) {
    if (vis[i][j] == 1) return;
    if (!safe(i, j)) return ;

    vis[i][j] = 1;
    // cout << i << " " << j << endl;

    kill(i-1, j-1);
    kill(i-1, j);
    kill(i-1, j+1);

    kill(i, j-1);
    kill(i, j+1);

    kill(i+1, j-1);
    kill(i+1, j);
    kill(i+1, j+1);
    return;
}


int solve() {
    // memset(grid, -1, sizeof grid);
    memset(vis, 0, sizeof vis);
    string s;
    // cout << " solving\n";
    for (int i=0; i<n; i++) {
        cin >> s;
        for (int j=0; j<n; j++) {
            grid[i][j] = s[j]-'0';
            // cout << grid[i][j];
        }
        // cout << endl;
    }
    int ans=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if ((grid[i][j]==1) && (vis[i][j]==0)) {
                ans++;
                // cout << i << " " << j << endl;
                kill(i, j);
            }
        }
    }
    return ans;
}

int main() {
    // int t,
    int cnt=1;;
    while (cin >> n) {
        cout << "Image number " << cnt << " contains " << solve() << " war eagles.\n";
        cnt++;
    } 
}
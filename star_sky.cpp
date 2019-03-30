#include<iostream>
using namespace std;
int f[101][101][11];
int main() {
    int n, q, c, x1, y1, x2, y2, t;
    cin >> n >> q >> c;
    for (int i=1; i<=n; i++) {
        cin >> x1 >> y1 >> t;
        f[x1][y1][t]++;
    }
   for(int i=1; i<=100; i++){
        for(int j=1; j<=100; j++){
            for(int k=0; k<=10; k++){
                f[i][j][k] += f[i-1][j][k] + f[i][j-1][k]-f[i-1][j-1][k];
            }
        }
    }
    while (q--) {
        cin >> t >> x1 >> y1 >> x2 >> y2;
        int temp[11];
        for(int i=0; i<=10; i++){
                temp[i] = f[x2][y2][i] + f[x1-1][y1-1][i] - f[x1-1][y2][i] - f[x2][y1-1][i];
        }
        long long ans=0;
        for(int i=0; i<=10; i++){
                ans += 1ll*(i+t)%(c+1) * temp[i];
        }
        cout << ans << endl;
    }
    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int dp[2][2][11][10][10], mx, k;
vector<int> num1, num2, num;
int f(int eq, int nz, int curL, int last, int ind, int n) {
    if (ind == num.size()) {
        if (curL == k && nz==1) return 1;
        return 0;
    }
    if (dp[eq][nz][curL][last][ind] != -1) return dp[eq][nz][curL][last][ind];
    int lmt = 9;
    if (eq == 0) {
        lmt = num[ind];
    }
    int ans = 0;
    for (int i=0; i<=lmt; i++) {
        int neq = eq;
        int n_curL = curL;
        int nLast = last;
        int nnz = nz;
        int nn = n*10 + i;
        if (i>0) nnz = 1;
        if (i < num[ind] || eq) neq = 1;
        //ignoring the current digit
        ans += f(neq, nnz, n_curL, nLast, ind+1, nn);
        if (i > last) {
            nLast = i;
            ans += f(neq, nnz, n_curL+1, nLast, ind+1, nn);
        }
    }
    (dp[eq][nz][curL][last][ind]=ans);
    return ans;
}

vector<int> getNum(int a) {
    vector<int> ans;
    while (a > 0) {
        ans.push_back(a%10);
        a /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

void solve(int a, int b) {
    if (a > b) swap(a, b);
    num1 = getNum(a-1);
    num2 = getNum(b);
    vector<int> temp;
    while (temp.size()+num1.size() < num2.size()) temp.push_back(0);
    for_each(num1.begin(), num1.end(), [&](int x) {
        temp.push_back(x);
    });
    num1 = temp;
    // cout << num1.size() << num2.size() << endl;
    for (k=1; k<=min(9, (int)num2.size()); k++) {
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        num = num2;
        // for (int i=0; i<=num[0]; i++) {
            ans += f(0, 0, 0, 0, 0, 0);
        // }
        num = num1;
        memset(dp, -1, sizeof(dp));
        // for (int i=0; i<=num[0]; i++) {
            ans -= f(0, 0, 0, 0, 0, 0);
        // }
        cout << k << " " << ans << endl;
    }
}

int main() {
    int a, b;
    cin >> a >> b;
    solve(a, b);
    return 0;
}
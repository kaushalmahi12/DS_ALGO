#include<cstring>
#include<iostream>
using namespace std;
const int mx = 5 * 1e3 + 2;
const int mod = 1e9 + 7;
int dp[mx][mx];
int a[mx], n;
int f(int pos, int nest) {
    if(nest < 0){
		return 0;
	}
	if(pos > n){
		return 1;
	}
	if(dp[pos][nest] != -1){
		return dp[pos][nest];
	}
	int res = f(pos , nest - 1);
	if(a[pos-1] == 0){
		res += f(pos + 1 , nest);
	}
	else{
		res += f(pos + 1 , nest + 1);
		res -= f(pos + 1 , nest);
	}
	if(res >= mod){
		res -= mod;
	}
	if(res < 0){
		res += mod;
	}
	return dp[pos][nest] = res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i=0; i<n; i++) {
        char c;
        cin >> c;
        if (c=='f') a[i] = 1;
        else a[i] = 0;
    }
    memset(dp, -1, sizeof(dp));
    cout << f(1, 0) << "\n";

    return 0;
}
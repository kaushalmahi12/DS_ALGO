// #include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int, int> pii;
int main() {
    ifstream cin("reststops.in");
    ofstream cout("reststops.out");
    int l, n, rf, rb;
    cin >> l >> n >> rf >> rb;
    int mul = rf-rb;
    vector<pii> p(n);
    for (int i=0; i<n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    sort(p.begin(), p.end(), [&](pii a, pii b) {
        return a.second > b.second;
    });

    long long ans = 1ll*mul*p[0].first*p[0].second;
    int covered = p[0].first;
    for (int i=1; i<n; i++) {
        if (p[i].first < covered) continue;
        ans += 1ll*mul*(p[i].first - covered)*p[i].second;
        covered = p[i].first;
    }
    cout << ans << "\n";
    return 0;
}
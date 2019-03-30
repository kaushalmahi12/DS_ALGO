#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i=0; i<n; i++) {
        int v;
        cin >> v;
        mp[v]++;
    }
    // bool poss = true;
    int cnt = 0, sum1=0, sum2=0;
    vector<int> first, sec;
    for (auto x: mp) {
        if (sum1 < sum2) sum1 += x.second, first.push_back(x.first);
        else sum2 += x.second, sec.push_back(x.first);
        cnt++;
    }
    if ((cnt>2 || cnt==1) || sum1!=sum2) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (auto x: mp) {
        cout << x.first << " ";
    }
    cout << "\n";
    return 0;
}
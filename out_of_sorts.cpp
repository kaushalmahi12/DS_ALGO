#include<fstream>
#include<algorithm>
using namespace std;

int bit[100005], n;
pair<int, int> a[100005];

void update(int x) {
    for (; x<n; ) { bit[x]++; x += (x & -x); }
}

int get(int x) {
    int ans=0;
    for (; x>0; ) { ans += bit[x]; x -= (x & -x); }
    return ans;
}

int main() {
    ifstream cin("sort.in");
    ofstream cout("sort.out");
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    auto amax = [&](int& f, int s) -> void { if (f < s) f = s; };
    sort(a+1, a+1+n);
    int ans = 1;
    for (int i=1; i<n; i++) {
        update(a[i].second);
        amax(ans, i-get(i));
        // cout << i-get(i) << "\n";
    }
    cout << ans << endl;
    return 0;
}
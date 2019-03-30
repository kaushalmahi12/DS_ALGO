#include<iostream>
using namespace std;
struct DS{
    int ch, count;
};
const int mx = 1000003;
DS ds[mx];
int ind;
string s;

int main() {
    cin >> s;
    int n = s.length();
    for (int i=0; i<n; i++) {
        if (s[i] != ds[ind].ch) ds[++ind].ch = s[i],ds[ind].count=0;
        ds[ind].count++;
    }
    // cout << ind << endl;
    int ans = 0;
    while (ind > 1) {
        int left=0;
        for (int i=1; i<=ind; i++) {
            int x = ds[i].ch;
            int y = ds[i].count-1-(i!=0 and i!=ind);
            if (y<=0) continue;
            if (x != ds[left].ch) ds[++left].ch = x;
            ds[left].count = y;
        }
        ind = left;
        ans++;
    }
    cout << ans << endl;
    return 0;
}
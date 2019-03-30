#include<iostream>
#include<vector>
using namespace std;

struct Seal {
    int x, y;
    Seal(int a, int b): x(a), y(b) {}
    int area() {
        return x*y;
    }
};

vector<Seal> arr;
int n, a, b, ans;

bool canFit(int i) {
    return (max(arr[i].x, arr[i].y) <= max(a, b));
}

void cal(int i, int j, int a, int b) {
    if ((arr[i].x + arr[j].x) <= a and max(arr[i].y, arr[j].y)<=b) {
                ans = max(ans, arr[i].area()+arr[j].area());
            }
            else if ((arr[i].x + arr[j].y) <= a and max(arr[i].y, arr[j].x)<=b) {
                 ans = max(ans, arr[i].area()+arr[j].area());
            }
            else if ((arr[i].y + arr[j].x) <= a and max(arr[i].x, arr[j].y)<=b) {
                 ans = max(ans, arr[i].area()+arr[j].area());
            }
            else if ((arr[i].y + arr[j].y) <= a and max(arr[i].x, arr[j].x)<=b) {
                 ans = max(ans, arr[i].area()+arr[j].area());
            }
}

int main() {
    int x, y, i=0;
    cin >> n >> a >> b;
    while (i++<n) {
        cin >> x >> y;
        arr.push_back(Seal(x, y));
    }
    // sort(arr.begin(), arr.end(), [](Seal& x, Seal& y) {
    //   return x.area() > y.area(); 
    // });
    for (i=0; i<n; i++) {
        if (!canFit(i)) {
            continue;
        }
        for (int j=i+1; j<n; j++) {
            if (!canFit(j)) continue;
            // cout << i << " " << j << endl;
            cal(i, j, a, b);
            cal(i, j, b, a);
        } 
    }
    cout << ans << endl;
    return 0;
}
#include <fstream>
#include <algorithm>
using namespace std;
struct point{
	int x, y;
	point(): x(0), y(0) {}
    int diff() const {
        return x-y; 
    }
    int plus() const {
        return x+y;
    }
	bool operator<(const point& other) const {
		return (other.diff() == diff()) ? (plus() > other.plus()) : (diff()<other.diff());
	}
};
int main() {
	// your code goes here
	int n;
    ifstream cin("mountains.in");
    ofstream cout("mountains.out");
	cin >> n;
	point peaks[n];
	for (int i=0; i<n; i++) {
        peaks[i] = point();
        cin >> peaks[i].x >> peaks[i].y;
    }
	sort(peaks, peaks+n);
	int mx = -1234, ans=0;
	for (int i=0; i<n; i++) {
		if (peaks[i].plus() >= mx) ans++, mx = peaks[i].plus();
	}
	cout << ans << "\n";
	return 0;
}
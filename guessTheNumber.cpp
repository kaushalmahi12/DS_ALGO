#include<iostream>
using namespace std;

int main(){
    string op;
    int l = 1, r = (int)1e6;
    while(1) {
        int mid = (l+r) >> 1;
        cout << mid << "\n";
        fflush(stdout);
        cin >> op; cin.ignore();
        if (l>r) {
            cout << "! " << r << "\n";
            break;
        }
        if (op == "<") {
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    fflush(stdout);
    return 0;
}
#include<iostream>
#include<cstring>
using namespace std;
int get(char* s) {
    int n = strlen(s);
    int out = 0;
    for (int i=0; i<n; i++) {
        out = out*10 + (s[i]-'0');
    }
    return out;
}
int main(int argc, char* args[]) {
    srand(time(NULL));
    int n = get(args[1]);
    cout << n << "\n";
    for (int i=0; i<n; i++) {
        if (rand()&1) {
            cout << 'f' << "\n";
        } else {
            cout << "s" << "\n";
        }
    }
    return 0;
}
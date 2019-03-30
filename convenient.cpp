#include<iostream>
using namespace std;

int main() {
    int n; ios_base::sync_with_stdio( 0 ), cin.tie( 0 ), cout.tie( 0 ), cin >> n;

    auto next = [ n ] ( auto &x ) { if ( --x < 0 ) x += n; };

    int a[ n ], s, f, t, u, v, sum = 0, max_sum = 0;

    for( int i = 0; i < n; i++ )
        cin >> a[ i ];

    cin >> s >> f, u = s - 1, v = f - 2;

    for( int i = u; i <= v; i++ )
        sum += a[ i ];

    for( int i = 1; i <= n; i++ )
    {
        if ( sum > max_sum )
            max_sum = sum, t = i;

        sum -= a[ v ], next( u ), next( v ), sum += a[ u ];
    }

    cout << t << "\n";
    return 0;
}
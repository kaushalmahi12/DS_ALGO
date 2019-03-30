// #include <fstream>
// #include <iostream>
// #include <string>
// #include <complex>
// #include <math.h>
// #include <set>
// #include <vector>
// #include <map>
// #include <queue>
// #include <stdio.h>
// #include <stack>
// #include <algorithm>т мом
// #include <list>
// #include <ctime>

// #include <memory.h>
// #include <assert.h>

// #define y0 sdkfaslhagaklsldk

// #define y1 aasdfasdfasdf
// #define yn askfhwqriuperikldjk
// #define j1 assdgsdgasghsf
// #define tm sdfjahlfasfh
// #define lr asgasgash
// #define norm asdfasdgasdgsd
// #define have adsgagshdshfhds
// #define ends asdgahhfdsfshdshfd

// #define eps 1e-8
// #define M_PI 3.141592653589793
// #define bsize 512

// #define ldouble long double
// using namespace std;

// #define bs 1000000007

// const int N = 400031;

// long double R,x1,y1,x2,y2;

// long double get_dist(long double x,long double y){
// 	return sqrt(x*x+y*y);
// }

// bool outside(){
// 	return get_dist(x2,y2)>R;
// }

// void show_answer(long double x,long double y,long double r){
// 	x+=x1;
// 	y+=y1;
// 	cout.precision(20);
// 	cout<<fixed<<x<<" "<<y<<" "<<r<<endl;
// }

// int main(){
// //	freopen("apache.in","r",stdin);
// //	freopen("apache.out","w",stdout);
// 	//freopen("input.txt", "r", stdin);
// 	//freopen("output.txt", "w", stdout);
// 	ios_base::sync_with_stdio(0);
// //	cin.tie(0);

// 	cin>>R>>x1>>y1>>x2>>y2;
// 	x2-=x1;
// 	y2-=y1;
// 	if (outside()){
// 		show_answer(0,0,R);
// 	}
// 	else
// 	{
// 		long double D=get_dist(x2,y2);
// 		long double dir=atan2(y2,x2);
// 		dir=dir+M_PI;
// 		long double diam=R+D;
// 		long double rad=diam/2;
// 		rad-=D;
// 		long double ax=rad*cos(dir);
// 		long double ay=rad*sin(dir);
// 		//cout.precision(20);
// 		show_answer(ax,ay,rad+D);
// 	}
// //	cin.get(); cin.get();
// 	return 0;
// }

#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
const double eps = 1e-9;
double x1, x2, Y1, y2, x, y, R;
typedef pair<double, double> point;

struct Circle {
    point center;
    double radius;
    Circle(point p, double r): center(p), radius(r) {}
};

struct Line {
    double m, c;
    Line(double m_, double c_): m(m_), c(c_){}

    double getYCorrespoindingTo(double x) {
        return m*x + c;
    }
};

struct LineCircleInterSection {
    point p1, p2, p;
    double a, b, c;
    LineCircleInterSection(Line l, Circle cr) {
        a = 1 + 1.0f * pow(l.m, 2);
        b = 2.0f * (cr.center.f - l.m*l.c + l.m*cr.center.s);
        c = pow(cr.center.f, 2) + pow(cr.center.s, 2) + pow(l.c, 2) - l.c * cr.center.s - pow(cr.radius, 2);
        double disc = pow(b, 2) - 4 * a * c;
        double x1 = 1.0f * (b + sqrt(disc)) / (2 * a);
        double x2 = 1.0f * (b - sqrt(disc)) / (2 * a);
        p1 = point(x1, l.getYCorrespoindingTo(x1));
        p2 = point(x2, l.getYCorrespoindingTo(x2));
    }

    double dist(point p11, point p22) {
        return sqrt(pow(p11.f-p22.f, 2) + pow(p11.s-p22.s, 2));
    }
    void print(point x) {
        cout << "[" << x.f << ", " << x.s << "]\n";
    }
    point getCenter(point p_) {
        print(point((p_.f+p2.f) / 2, (p_.s+p2.s) / 2));
        print(point((p_.f+p1.f) / 2, (p_.s+p1.s) / 2));
        if (dist(p_, p1)+eps < dist(p_, p2)) {
            return point((p_.f+p2.f) / 2, (p_.s+p2.s) / 2);
        }
        return point((p_.f+p1.f) / 2, (p_.s+p1.s) / 2);
    }
};

int main() {
    cin >> R >> x1 >> Y1 >> x2 >> y2;
    auto dist = [&]()->double {
        return 1.0f * sqrt(pow(x1-x2, 2)+pow(Y1-y2, 2));
    };
    cout.precision(20);
    if(dist() < eps) {
        cout << (x1 + R/2) << " " << Y1 << " "  << R/2 << "\n"; 
    }
    else if (dist() < R) {
        double m = 1.0f * (y2-Y1) / (x2-x1);
        double c = Y1 - m*x1;
        Line l(m, c);
        Circle cr(point(x1, Y1), R);
        LineCircleInterSection ds(l, cr);
        point p = ds.getCenter(point(x2, y2));
        double r = (R + dist()) /2;
        cout << p.f << " " << p.s << " " << r << "\n";
    } else {
        cout << x1 << " " << Y1 << " " << R << "\n"; 
    }
    return 0;
}
#include <bits/stdc++.h>
const double EPS = 1e-9;

double DEG_to_RAD(double x)
{
    return x * M_PI / 180;
}

struct point
{
    double x, y;
    point() { x = y = 0.0; }
    point(double _x, double _y) : x(_x), y(_y) {}

    bool operator<(point other) const
    { // override less than operator
        if (fabs(x - other.x) > EPS)
            return x < other.x;
        return y < other.y;
    }

    bool operator==(point other) const
    {
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
    }

    double distTo(point p2)
    { // Euclidean distance // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
        return hypot(x - p2.x, y - p2.y);
    }

    point rotate(point p, double theta)
    {
        double rad = DEG_to_RAD(theta); // multiply theta with PI / 180.0
        return point(p.x * cos(rad) - p.y * sin(rad), p.x * sin(rad) + p.y * cos(rad));
    }
};
// useful for sorting // first criteria , by x-coordinate // second criteria, by y-coordinate

struct line
{
    double a, b, c;

    void pointsToLine(point p1, point p2, line &l)
    {
        if (fabs(p1.x - p2.x) < EPS)
        { // vertical line is fine
            l.a = 1.0;
            l.b = 0.0;
            l.c = -p1.x;
        }
        else
        {
            // default values
            l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
            l.b = 1.0; // IMPORTANT: we fix the value of b to 1.0 l.c = -(double)(l.a * p1.x) - p1.y;
        }
    }

    bool areParallel(line l1, line l2)
    { // check coefficients a & b
        return (fabs(l1.a - l2.a) < EPS) && (fabs(l1.b - l2.b) < EPS);
    }
    bool areSame(line l1, line l2)
    { // also check coefficient c
        return areParallel(l1, l2) && (fabs(l1.c - l2.c) < EPS);
    }
    bool areIntersect(line l1, line l2, point &p)
    {
        if (areParallel(l1, l2))
            return false; // no intersection // solve system of 2 linear algebraic equations with 2 unknowns
        p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
        // special case: test for vertical line to avoid division by zero
        if (fabs(l1.b) > EPS)
            p.y = -(l1.a * p.x + l1.c);
        else
            p.y = -(l2.a * p.x + l2.c);
        return true;
    }
};

struct vec
{
    double x, y; // name: ‘vec’ is different from STL vector
    vec(double _x, double _y) : x(_x), y(_y) {}
    vec toVec(point a, point b)
    { // convert 2 points to vector a->b
        return vec(b.x - a.x, b.y - a.y);
    }
    vec scale(vec v, double s)
    {
        return vec(v.x * s, v.y * s);
    }
    // nonnegative s = [<1 .. 1 .. >1] // shorter.same.longer
    point translate(point p, vec v)
    {
        return point(p.x + v.x, p.y + v.y); // translate p according to vF
    }

    double dot(vec a, vec b) { 
        return (a.x * b.x + a.y * b.y);
    }
    
    double magnitudeOf(vec v) {
        return v.x * v.x + v.y * v.y;
    }

    // returns the distance from p to the line defined by
    // two points a and b (a and b must be different)
    // the closest point is stored in the 4th parameter (byref)
    double distToLine(point p, point a, point b, point &c)
    {
        // formula: c = a + u * ab
        vec ap = toVec(a, p), ab = toVec(a, b);
        double u = dot(ap, ab) / magnitudeOf(ab);
        c = translate(a, scale(ab, u)); // translate a to c
        return p.distTo(c);              // Euclidean distance between p and c
    }
};
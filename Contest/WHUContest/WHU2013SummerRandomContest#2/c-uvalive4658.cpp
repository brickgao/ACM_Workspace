#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const double eps = 1e-8;

int sgn(double d) {
    return d > eps ? 1 : (d < -eps ? -1 : 0);
}

struct point {
    double x, y;
    int id;
    point(double _x = 0, double _y = 0): x(_x), y(_y) {
    }
    void input() {
        scanf("%lf%lf", &x, &y);
    }
    double len() const {
        return sqrt(x * x + y * y);
    }
    point trunc(double l) const {
        double r = l / len();
        return point(x * r, y * r);
    }
    point rotate_left(double ang) const {
        double c = cos(ang), s = sin(ang);
        return point(x * c - y * s, y * c + x * s);
    }
    point rotate_right(double ang) const {
        double c = cos(ang), s = sin(ang);
        return point(x * c + y * s, y * c - x * s);
    }
    point rotate_left() const {
        return point(-y, x);
    }
    point rotate_right() const {
        return point(y, -x);
    }
};

point operator+(const point& p1, const point& p2) {
    return point(p1.x + p2.x, p1.y + p2.y);
}

point operator-(const point& p1, const point& p2) {
    return point(p1.x - p2.x, p1.y - p2.y);
}

double operator^(const point& p1, const point& p2) {
    return p1.x * p2.x + p1.y * p2.y;
}

double operator*(const point& p1, const point& p2) {
    return p1.x * p2.y - p1.y * p2.x;
}

point operator*(const point& p, double r) {
    return point(p.x * r, p.y * r);
}

point operator/(const point& p, double r) {
    return point(p.x / r, p.y / r);
}
point p[100005];
bool com1(point p1,point p2)
{
	if(p1.y==p2.y)
		return p1.x<p2.x;
	return p1.y<p2.y;
}
bool com2(point p1,point p2)
{
	return (p1-p[1])*(p2-p[1])>0;
}
int main()
{
	int casenum;
	scanf("%d",&casenum);
	while(casenum--)
	{
		int n,k;
		scanf("%d %d",&n,&k);
		for(int i=1;i<=n;i++)
		{
			p[i].input();
			p[i].id=i;
		}
		sort(p+1,p+1+n,com1);
		sort(p+2,p+1+n,com2);
		for(int i=1;i<=k;i++)
			printf("%d\n",p[i].id);
	}
	return 0;
}


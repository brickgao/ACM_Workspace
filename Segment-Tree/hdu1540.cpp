//By Brickgao
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
const int maxn = 50010;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

int lsum[maxn << 2], rsum[maxn << 2];
int n, m;

void PushUp(int l, int r, int rt) {
    int m = (l + r) >> 1;
	lsum[rt] = lsum[rt << 1];
	rsum[rt] = rsum[rt << 1 | 1];
    if(lsum[rt << 1] == m - l + 1)
        lsum[rt] += lsum[rt << 1 | 1];
    if(rsum[rt << 1 | 1] == r - m)
        rsum[rt] += rsum[rt << 1];
}

void build(int l,int r,int rt) {
	lsum[rt] = rsum[rt] = r - l + 1;
	if (l == r) return ;
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
}

void update(int c, int p, int l, int r, int rt) {
	if (p <= l && r <= p) {
        lsum[rt] = rsum[rt] = c;
		return ;
	}
	int m = (l + r) >> 1;
	if (p <= m) 
        update(c, p, lson);
    else 
        update(c, p, rson);
    PushUp(l, r, rt);
}

int query(int w, int l, int r, int rt) {
    int m = (l + r) >> 1;
    if(w <= l && r <= w) {
        return lsum[rt];
    }
    if(w <= m) {
        if(m - rsum[rt << 1] + 1 <= w) {
            return rsum[rt << 1] + lsum[rt << 1 | 1];
        }
        else {
            return query(w, lson);
        }
    }
    else {
        if(m + lsum[rt << 1 | 1] >= w) {
            return rsum[rt << 1] + lsum[rt << 1 | 1];
        }
        else {
            return query(w, rson);
        }
    }
}

int main() {
    while(scanf("%d%d", &n, &m) != EOF) {
    stack <int> st;
    build(1, n ,1);
    while(m --) {
        char op[5];
        scanf("%s", op);
        if(op[0] == 'D') {
            int x;
            scanf("%d", &x);
            update(0, x, 1, n, 1);
            st.push(x);
        }
        if(op[0] == 'Q') {
            int x;
            scanf("%d", &x);
            printf("%d\n", query(x, 1, n, 1));
        }
        if(op[0] == 'R') {
            int bef = st.top();
            st.pop();
            update(1, bef, 1, n, 1);
        }
    }
    }
    return 0;
}


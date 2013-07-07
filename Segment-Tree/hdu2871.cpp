//By Brickgao
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
const int maxn = 50010;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

typedef struct node {
    int l, r;
    bool operator < (const node &cmp) const {
        return l < cmp.l;
    }
} node;

int sum[maxn << 2];
int lsum[maxn << 2], rsum[maxn << 2];
int cover[maxn << 2];
int n, m;
vector <node> mem;
node tno;

void PushUP(int rt, int m) {
    lsum[rt] = lsum[rt << 1];
    rsum[rt] = rsum[rt << 1 | 1];
    if(lsum[rt] == m - (m >> 1)) lsum[rt] += lsum[rt << 1 | 1];
    if(rsum[rt] == (m >> 1))    rsum[rt] += rsum[rt << 1];
    sum[rt] = max(lsum[rt << 1 | 1] + rsum[rt << 1], max(sum[rt << 1], sum[rt << 1 | 1]));
}

void PushDown(int rt, int m) {
    if(cover[rt] != -1) {
        cover[rt << 1] = cover[rt << 1 | 1] = cover[rt];
        sum[rt << 1] = lsum[rt << 1] = rsum[rt << 1] = cover[rt] ? 0 : m - (m >> 1);
        sum[rt << 1 | 1] = lsum[rt << 1 | 1] = rsum[rt << 1 | 1] = cover[rt] ? 0 : (m >> 1);
        cover[rt] = -1;
    }
}

void build(int l, int r, int rt) {
    sum[rt] = lsum[rt] = rsum[rt] = r - l + 1;
    cover[rt] = -1;
    if(l == r)  {
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
}

void update(int L, int R, int c, int l, int r, int rt) {
    if(L <= l && r <= R) {
        sum[rt] = lsum[rt] = rsum[rt] = c ? 0 : r - l + 1;
        cover[rt] = c;
        return;
    }
    PushDown(rt, r - l + 1);
    int m = (l + r) >> 1;
    if(L <= m)  update(L, R, c, lson);
    if(m < R)   update(L, R, c, rson);
    PushUP(rt, r - l + 1);
}

int query(int w, int l, int r, int rt) {
    if(l == r)  return l;
    PushDown(rt, r - l + 1);
    int m = (l + r) >> 1;
    if(sum[rt << 1] >= w)   return query(w, lson);
    else if (rsum[rt << 1] + lsum[rt << 1 | 1] >= w) return m - rsum[rt << 1] + 1;
    return query(w, rson);
}

int main() {
    vector <node> :: iterator it;
    while(scanf("%d%d", &n, &m) != EOF) {
        char s[10];
        build(1, n, 1);
        mem.clear();
        for(int i = 0; i < m; i ++) {
            scanf("%s", s);
            if(s[0] == 'N') {
                int a;
                scanf("%d", &a);
                if(sum[1] < a)  puts("Reject New");
                else {
                    int p = query(a, 1, n, 1);
                    update(p, p + a - 1, 1, 1, n, 1);
                    tno.l = p;
                    tno.r = p + a - 1;
                    it = upper_bound(mem.begin(), mem.end(), tno);
                    mem.insert(it, tno);
                    printf("New at %d\n", p);
                }
            }
            if(s[0] == 'F') {
                int a;
                scanf("%d", &a);
                tno.l = a;
                tno.r = a;
                int pos = upper_bound(mem.begin(), mem.end(), tno) - mem.begin() - 1;
                if(pos == -1 || mem[pos].r < a)  puts("Reject Free");
                else {
                    printf("Free from %d to %d\n", mem[pos].l, mem[pos].r);
                    update(mem[pos].l, mem[pos].r, 0, 1, n, 1);
                    mem.erase(mem.begin() + pos);
                }
            }
            if(s[0] == 'G') {
                int a;
                scanf("%d", &a);
                if(a > SZ(mem)) 
                    puts("Reject Get");
                else
                    printf("Get at %d\n", mem[a - 1].l);
            }
            if(s[0] == 'R') {
                update(1, n, 0, 1, n, 1);
                puts("Reset Now");
                mem.clear();
            }
        }
        puts("");
    }
}

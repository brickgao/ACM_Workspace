//By Brickgao
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
#define LL long long
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

typedef struct record {
    int num;
    LL r;
    bool operator < (const record &cmp) const {
        return r > cmp.r;
    }
} record;

typedef struct tree {
    int left, right;
} tree;

int t;
int n;
LL rec[500010];
tree p[1000010];
LL ans = 0;

void dfs(int u, LL depth) {
    if(p[u].right == p[u].left && p[u].right == -1) {
        ans += depth * rec[u];
        return;
    }
    if(p[u].left != -1)
        dfs(p[u].left, depth + 1);
    if(p[u].right != -1)
        dfs(p[u].right, depth + 1);
}

int main() {
    while(scanf("%d", &t) != EOF) {
        bool blank = false;
        for(int T = 0; T < t ; ++ T) {
            ans = 0;
            if(blank)   puts("");
            else    blank = true;
            priority_queue <record> q;
            scanf("%d", &n);
            for(int i = 0; i <= n * 2 + 1; ++ i)   p[i].left = p[i].right = -1;
            int top = n;
            for(int i = 0; i < n; ++ i) {
                record tmp;
                scanf("%lld", &rec[i]);
                tmp.num = i, tmp.r = rec[i];
                q.push(tmp);
            }
            while(SZ(q) > 1) {
                record top1 = q.top(); q.pop();
                record top2 = q.top(); q.pop();
                record ne;
                ne.num = top ++;
                ne.r = top1.r + top2.r;
                q.push(ne);
                p[ne.num].right = top1.num;
                p[ne.num].left = top2.num;
            }
            dfs(top - 1, 0);
            printf("%lld\n", ans);
        }
    }
    return 0;
}


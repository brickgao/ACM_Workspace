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
const int maxn = 500010;
const int INF = 1000000009;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

int sum[maxn << 2];
int rec[maxn];
int arr[maxn];

void PushUP(int rt) {
    sum[rt] = min(sum[rt << 1], sum[rt << 1 | 1]);
}

void update(int p, int l, int r, int rt) {
    if(l == r && l == p) {
        sum[rt] = p;
        return;
    }
    int m = (l + r) >> 1;
    if(p <= m)  update(p, lson);
    else    update(p, rson);
    PushUP(rt);
}

int query(int L, int R, int l, int r, int rt) {
    if(sum[rt] == INF)  return INF;
    if(L <= l && r <= R) {
        return sum[rt];
    }
    int ret = INF;
    int m = (l + r) >> 1;
    if(L <= m)  ret = min(ret, query(L, R, lson));
    if(R > m)  ret = min(ret, query(L, R, rson));
    return ret;
}

int main() {
    bool flag = false;
    int t, caseno = 1;
    while(scanf("%d", &t) != EOF && t) {
        if(flag) {
            puts("");
        }
        else {
            flag = true;
        }
        int maxr = maxn - 10;
        printf("Case %d:\n", caseno ++);
        int len = (maxn << 2);
        for(int i = 0; i < len; i ++) {
            sum[i] = INF;
        }
        int m = 0;
        for(int i = 0; i < t; i ++) {
            char op[3];
            int num;
            scanf("%s%d", op, &num);
            if(op[0] == 'B') {
                update(num, 1, maxr, 1);
                arr[m ++] = num;
                rec[num] = m;
            }
            else {
                int ans = -1, res = INF;
                if(maxr * (log(maxr) / log(2)) > m * num) {
                    for(int j = m - 1; j >= 0; j --) {
                        if(arr[j] % num < res) {
                            ans = rec[arr[j]];
                            res = arr[j] % num;
                        }
                        if(res == 0)
                            break;
                    }
                    printf("%d\n", ans);
                    continue;
                }
                for(int j = 0; ; j ++) {
                    int le = j * num;
                    int ri = (j + 1) * num - 1;
                    if(le == 0) le = 1;
                    if(le > maxr)   break;
                    if(ri > maxr)    ri = maxr;
                    int tmp = query(le, ri, 1, maxr, 1);
                    if(tmp != INF) {
                        if(tmp % num == res) {
                            if(rec[tmp] > ans) {
                                ans = rec[tmp];
                            }
                        }
                        else if(tmp % num < res) {
                            res = tmp % num;
                            ans = rec[tmp];
                        }
                    }
                }
                printf("%d\n", ans);
                
            }
        }
    }
    return 0;
}


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
#define cmp(a, b) ((a) > (b))
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

typedef struct person {
    int s, b;
    int pos;
    bool operator < (const person &cmp) const {
        if(s == cmp.s)
            return b > cmp.b;
        else
            return s < cmp.s;
    }
} person;

int t;
int n;
person rec[100010];
int len_min[100010];
int rec_pos[100010];

int binary_search(int a, int b, int k) {
    int mid;
    while(a < b)
        if(cmp(k, rec[len_min[mid = (a + b) >> 1]].b))
                a = mid + 1;
        else
                b = mid;
    return a;
}

int main() {
    scanf("%d", &t);
    for(int T = 0; T < t; ++ T) {
        if(T)   puts("");
        scanf("%d", &n);
        for(int i = 0; i < n; ++ i) {
            scanf("%d%d", &rec[i].s, &rec[i].b);
            rec[i].pos = i + 1;
        }
        sort(rec, rec + n);
        int a = 0, b = 1, k;
        len_min[0] = 0, rec_pos[0] = 0;
        for(int i = 1; i < n; ++ i) {
            if(rec[len_min[k = binary_search(a, b - 1, rec[i].b)]].b >= rec[i].b) {
                len_min[k] = i;
                rec_pos[i] = len_min[k - 1];
            }
            else {
                rec_pos[i] = len_min[b - 1];
                len_min[b ++] = i;
            }
        }
        printf("%d\n", b);
        int tmp = len_min[b - 1];
        printf("%d", rec[tmp].pos);
        for(int i = 1; i < b; ++ i) {
            tmp = rec_pos[tmp];
            printf(" %d", rec[tmp].pos);
        }
        puts("");
    }
    return 0;
}


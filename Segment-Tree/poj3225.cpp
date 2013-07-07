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
const int maxn = 65540;
const int maxr = 65535 << 1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

int sum[maxn << 3];
int XOR[maxn << 3];
bool hash[maxn << 1];

void FXOR(int rt) {
    if(sum[rt] != -1)
        sum[rt] ^= 1;
    else
        XOR[rt] ^= 1;
}

void PushDown(int rt) {
    if(sum[rt] != -1) {
        sum[rt << 1] = sum[rt << 1 | 1] = sum[rt];
        XOR[rt << 1] = XOR[rt << 1 | 1] = 0;
    }
    if(XOR[rt]) {
        FXOR(rt << 1);
        FXOR(rt << 1 | 1);
        XOR[rt] = 0;
    }
}

void update(char op, int L, int R, int l, int r, int rt) {
    if(L <= l && r <= R) {
        if(op == 'U') {
            sum[rt] = 1;
            XOR[rt] = 0;
        }
        if(op == 'D') {
            sum[rt] = 0;
            XOR[rt] = 0;
        }
        if(op == 'C' || op == 'S') {
            FXOR(rt);
        }
        return;
    }
    PushDown(rt);
    int m = (l + r) >> 1;
    if(L <= m)  update(op, L, R, lson);
    else if(op == 'I' || op == 'C') {
        XOR[rt << 1] = sum[rt << 1] = 0;
    }
    if(m < R)   update(op, L, R, rson);
    else if(op == 'I' || op == 'C') {
        XOR[rt << 1 | 1] = sum[rt << 1 | 1] = 0;
    }
    sum[rt] = -1;
}

void query(int L, int R, int l, int r, int rt) {
    if(sum[rt] != -1) {
        if(sum[rt] == 1)
            for(int i = l; i <= r; i ++) 
                hash[i] = true;
        return;
    }
    if(l == r)  return;
    PushDown(rt);
    int m = (l + r) >> 1;
    if(L <= m)  query(L, R, lson);
    if(m < R)   query(L, R, rson);
}

int main() {
    char op, sym1, sym2;
    int num1, num2;
    memset(sum, 0, sizeof(sum));
    memset(hash, false, sizeof(hash));
    while(scanf("%c %c%d,%d%c\n", &op, &sym1, &num1, &num2, &sym2) != EOF) {
        if(sym1 == '[')
            num1 = num1 << 1;
        else
            num1 = (num1 << 1) + 1;
        if(sym2 == ']')
            num2 = num2 << 1;
        else
            num2 = (num2 << 1) - 1;
        //cout << op << " " << num1 << " " << num2 << endl;
        if(num1 > num2 && (op == 'C' || op == 'I')) {
            sum[1] = XOR[1] = 0;
            continue;
        }
        update(op, num1, num2, 0, maxr, 1);
    }
    query(0, maxr, 0, maxr, 1);
    int flag = false;
    for(int i = 0; i <= maxr; i ++) {
        int st, ed;
        if(hash[i]) {
            if(flag)   printf(" ");
            flag = true;
            st = i;
            while(i <= maxr && hash[i]) {
                i ++;
            }
            if(i <= maxr && !hash[i])   i --;
            ed = i;
            if(st & 1)
                printf("(%d,", (st - 1) >> 1);
            else
                printf("[%d,", st >> 1);
            if(ed & 1)
                printf("%d)", (ed + 1) >> 1);
            else
                printf("%d]", ed >> 1);
        }
    }
    if(!flag)
        puts("empty set");
    else
        printf("\n");
    return 0;
}


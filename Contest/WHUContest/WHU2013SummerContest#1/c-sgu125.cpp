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
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

int n;
int b[4][4];
int a[4][4];
int move[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool flag = false;

bool check(int x, int y, int s) {
    int res = 0;
    for(int i = 0; i < 4; ++ i) {
        int nx = x + move[i][0];
        int ny = y + move[i][1];
        if(nx < 0 || nx >= s)   continue;
        if(ny < 0 || ny >= s)   continue;
        if(a[nx][ny] > a[x][y]) ++ res;
    }
    if(res == b[x][y])
        return true;
    else
        return false;
}

void op2() {
    for(int i1 = 1; i1 <= 4; ++ i1)
        for(int i2 = 1; i2 <= 4; ++ i2)
            for(int i3 = 1; i3 <= 4; ++ i3)
                for(int i4 = 1; i4 <= 4; ++ i4) {
                    a[0][0] = i1, a[0][1] = i2, a[1][0] = i3, a[1][1] = i4;
                    int res = 0;
                    for(int i = 0; i < 2; ++ i)
                        for(int j = 0; j < 2; ++ j)
                            if(check(i, j, 2))
                                ++ res;
                    if(res == 4) {
                        flag = true;
                        return;
                    }
                }
}

bool cope(int x, int y, int mo) {
    if(mo == 0) {
        int rec[4], num = 0;
        for(int i = 0; i < 4; ++ i) {
            int nx = x + move[i][0];
            int ny = y + move[i][1];
            if(nx < 0 || nx >= 3)   continue;
            if(ny < 0 || ny >= 3)   continue;
            rec[num ++] = a[nx][ny];
        }
        sort(rec, rec + num);
        if(b[x][y] == 0) {
            a[x][y] = rec[2];
            return check(x, y, 3);
        }
        else if(b[x][y] == 1) {
            a[x][y] = rec[1];
            return check(x, y, 3);
        }
        else if(b[x][y] == 2) {
            a[x][y] = rec[0];
            return check(x, y, 3);
        }
        else if(b[x][y] == 3) {
            a[x][y] = rec[0] - 1;
            return check(x, y, 3);
        }
    }
    else {
        for(int i = 0; i <= 9; ++ i) {
            if(a[x - 1][y] == i || a[x][y - 1] == i || a[x + 1][y] == i || a[x][y + 1] == i) continue; 
            a[x][y] = i;
            if(check(x, y, 3))   return true;
        }
        return false;
    }
    return false;
}

void op3() {
    for(int i1 = 1; i1 <= 9; ++ i1)
        for(int i2 = 1; i2 <= 9; ++ i2)
            for(int i3 = 1; i3 <= 9; ++ i3)
                for(int i4 = 1; i4 <= 9; ++ i4)
                    for(int i5 = 1; i5 <= 9; ++ i5) {
                        a[0][0] = i1, a[0][2] = i2, a[2][0] = i3, a[2][2] = i4, a[1][1] = i5;
                        for(int j1 = 0; j1 <= 1; ++ j1)
                            for(int j2 = 0; j2 <= 1; ++ j2)
                                for(int j3 = 0; j3 <= 1; ++ j3)
                                    for(int j4 = 0; j4 <= 1; ++ j4) {
                                        if(cope(0, 1, j1) && cope(1, 0, j2) && cope(1, 2, j3) && cope(2, 1, j4)) {
                                            int res = 0;
                                            for(int i = 0; i < 3; ++ i)
                                                for(int j = 0; j < 3; ++ j)
                                                    if(check(i, j, 3))
                                                        ++ res;
//                                            printf("%d %d %d\n", a[0][0], a[0][1], a[0][2]);
//                                            printf("%d %d %d\n", a[1][0], a[1][1], a[1][2]);
//                                            printf("%d %d %d\n", a[2][0], a[2][1], a[2][2]);
                                            if(res == 9) {
                                                flag = true;
                                                return;
                                            }
                                        }
                                    }
                    }
}

int main() {
    while(scanf("%d", &n) != EOF) {
        flag = false;
        for(int i = 0; i < n; ++ i)
            for(int j = 0; j < n; ++ j)
                scanf("%d", &b[i][j]);
        if(n == 1) {
            if(b[0][0] == 0)
                puts("1");
            else
                puts("NO SOLUTION");
        }
        if(n == 2) {
            op2();
            if(!flag)
                puts("NO SOLUTION");
            else {
                printf("%d %d\n", a[0][0], a[0][1]);
                printf("%d %d\n", a[1][0], a[1][1]);
            }
        }
        if(n == 3) {
            op3();
            if(!flag)
                puts("NO SOLUTION");
            else {
                printf("%d %d %d\n", a[0][0], a[0][1], a[0][2]);
                printf("%d %d %d\n", a[1][0], a[1][1], a[1][2]);
                printf("%d %d %d\n", a[2][0], a[2][1], a[2][2]);
            }
        }
    }
    return 0;
}


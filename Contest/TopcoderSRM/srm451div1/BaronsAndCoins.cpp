// BEGIN CUT HERE

#include <conio.h>
#include <sstream>
/*
*/
#define debuging
#ifdef debuging
#define FIN  {freopen("new.in" , "r" , stdin) ;}
#define FOUT {freopen("new.out" , "w" , stdout) ;}
#define OUT(x)  {cout<< #x << "  : " << x <<endl ;}
#define ERR(x)  {cout<<"#error: "<< x ; while(1) ;}
#endif
// END CUT HERE
#ifndef debuging
#define FIN  ;
#define FOUT ;
#define OUT(x)  ;
#define ERR(x)  ;
#endif
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std ;
#define For(i , n) for(int i = 0 ; i < (n) ; ++i)
#define SZ(x)  (int)((x).size())
typedef long long lint ;
typedef struct pos {
    int x, y;
    pos() {}
    pos(int a, int b): x(a), y(b) {}
    bool operator < (const pos &cmp) const {
        if(y == cmp.y)
            return x < cmp.x;
        return y < cmp.y;
    }
} pos;
const int maxint = -1u>>2 ;
const double eps = 1e-6 ; 
class BaronsAndCoins
{
public:
int getMaximum(vector <int> x, vector <int> y)
{
    int dp[60][60];
    vector <pos> p;
    memset(dp, -1, sizeof(dp));
    p.push_back(pos(0, 0));
    for(int i = 0; i < SZ(x); ++ i)
        p.push_back(pos(x[i], y[i]));
    sort(p.begin(), p.end());
    dp[0][0] = 0;
    for(int i = 0; i < SZ(p); ++ i)
        for(int j = i + 1; j < SZ(p); ++ j) {
            if(p[i].y == p[j].y || p[i].x == p[j].x)    continue;
            for(int k = 0; k <= i; ++ k)
                if(dp[i][k] != -1) {
                    int col = p[j].x - p[i].x;
                    int row = p[j].y - p[i].y;
                    int now = dp[i][k] * row + row * (row + 1) / 2;
                    if(now > col)   continue;
                    int ret = dp[i][k] + row + (int)ceil((double)(col - now) / (double)row);
                    if(dp[j][k + 1] == -1)  dp[j][k + 1] = ret;
                    else                    dp[j][k + 1] = min(ret, dp[j][k + 1]);
                }
        }
    int ans = 0;
    for(int i = 0; i < SZ(p); ++ i)
        for(int j = 0; j < SZ(p); ++ j) {
            if(dp[i][j] != -1)  ans = max(ans, j);
        }
    return ans;
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {15, 5, 30}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4, 5, 6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, getMaximum(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {19}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(1, Arg2, getMaximum(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1, 3, 6, 10, 15, 21}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3, 4, 5, 6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(2, Arg2, getMaximum(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {5, 10, 15, 20, 25, 30, 35, 40, 45}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 1, 2, 2, 2, 3, 3, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(3, Arg2, getMaximum(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1, 3, 6, 10, 22, 35, 50, 66}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3, 1, 2, 3, 4, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(4, Arg2, getMaximum(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
BaronsAndCoins ___test;
___test.run_test(-1);
getch() ;
return 0;
}
// END CUT HERE

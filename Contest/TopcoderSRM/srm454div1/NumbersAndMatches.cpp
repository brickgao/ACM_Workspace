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
#define LL long long
#define For(i , n) for(int i = 0 ; i < (n) ; ++i)
#define SZ(x)  (int)((x).size())
typedef long long lint ;
const int maxint = -1u>>2 ;
const double eps = 1e-6 ; 
int num[10] = {6, 3, 5, 5, 4, 5, 6, 3, 7, 6};
int mv[10][10] = {
    {0, 0, 1, 1, 1, 1, 1, 0, 0, 1},
    {0, 0, 1, 0, 1, 1, 1, 1, 0, 0},
    {1, 1, 0, 1, 2, 2, 1, 1, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 0, 0, 0},
    {1, 1, 2, 1, 0, 1, 1, 1, 0, 0},
    {1, 1, 2, 1, 1, 0, 0, 1, 0, 0},
    {1, 1, 1, 1, 1, 0, 0, 1, 0, 1},
    {0, 1, 1, 0, 1, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 1, 0, 0, 0}};
int rec[20];
LL dp[20][300][300];
class NumbersAndMatches
{
public:
long long differentNumbers(long long N, int K)
{
    LL tmp = N;
    int len = 0;
    while(tmp > 0) {
        rec[len ++] = tmp % 10;
        tmp /= 10;
    }
    memset(dp, 0, sizeof(dp));
    dp[0][K][0] = 1;
    for(int i = 0; i < len; ++ i) {
        for(int j = -K; j <= K; ++ j) {
            for(int k = 0; k <= K; ++ k) {
                if(dp[i][j + K][k])
                    for(int l = 0; l < 10; ++ l) {
                        int gi = num[rec[i]] - num[l];
                        int nj = j + gi;
                        int nk = k + mv[rec[i]][l];
                        if(j * gi < 0)
                            nk += min(abs(j), abs(gi));
                        if(-K <= nj && nj <= K && 0 <= nk && nk <= K)
                            dp[i + 1][nj + K][nk] += dp[i][j + K][k];
                            
                    }
            }
        }
    }
    LL ans = 0;
    for(int i = 0; i <= K; ++ i) {
        ans += dp[len][K][i];
    }
    return ans;
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 10LL; int Arg1 = 1; long long Arg2 = 4LL; verify_case(0, Arg2, differentNumbers(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 23LL; int Arg1 = 1; long long Arg2 = 4LL; verify_case(1, Arg2, differentNumbers(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 66LL; int Arg1 = 2; long long Arg2 = 15LL; verify_case(2, Arg2, differentNumbers(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 888888888LL; int Arg1 = 100; long long Arg2 = 1LL; verify_case(3, Arg2, differentNumbers(Arg0, Arg1)); }
	void test_case_4() { long long Arg0 = 444444444444444444LL; int Arg1 = 2; long long Arg2 = 1LL; verify_case(4, Arg2, differentNumbers(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
NumbersAndMatches ___test;
___test.run_test(-1);
getch() ;
return 0;
}
// END CUT HERE

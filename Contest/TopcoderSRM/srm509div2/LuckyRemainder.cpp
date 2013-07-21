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
const int maxint = -1u>>2 ;
const double eps = 1e-6 ; 
class LuckyRemainder
{
public:
int getLuckyRemainder(string X)
{
    int c[55][55];
    int tenpow[55];
    int ans = 0;
    memset(c, 0, sizeof(c));
    tenpow[0] = 1;
    for(int i = 1; i <= 54; ++ i)
        tenpow[i] = tenpow[i - 1] * 10 % 9;
    for(int i = 0; i <= 54; ++ i) {
        c[i][0] = c[i][i] = 1;
        for(int j = 1; j < i; ++ j) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % 9;
        }
    }
    for(int i = 0; i < SZ(X); ++ i) {
        int num = X[i] - '0';
        for(int j = 0; j <= SZ(X) - i - 1; ++ j) {
            for(int k = 0; k <= i; ++ k) {
                ans = (ans + (num * tenpow[SZ(X) - i - j - 1] * (c[SZ(X) - i - 1][j] % 9) * (c[i][k] % 9)) % 9) % 9;
            }
        }
    }
    return int(ans);
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "9999929999999999999999999999999999999999"; int Arg1 = 7; verify_case(0, Arg1, getLuckyRemainder(Arg0)); }
	void test_case_1() { string Arg0 = "24816"; int Arg1 = 3; verify_case(1, Arg1, getLuckyRemainder(Arg0)); }
	void test_case_2() { string Arg0 = "9999999999999999999999999999999999999991"; int Arg1 = 8; verify_case(2, Arg1, getLuckyRemainder(Arg0)); }
	void test_case_3() { string Arg0 = "11235813213455"; int Arg1 = 7; verify_case(3, Arg1, getLuckyRemainder(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
LuckyRemainder ___test;
___test.run_test(-1);
getch() ;
return 0;
}
// END CUT HERE

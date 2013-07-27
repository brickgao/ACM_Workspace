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
#define LL long long
using namespace std ;
#define For(i , n) for(int i = 0 ; i < (n) ; ++i)
#define SZ(x)  (int)((x).size())
typedef long long lint ;
const int maxint = -1u>>2 ;
const double eps = 1e-6 ; 

LL c[1050][1050];

class StringWeightDiv2
{
public:
int countMinimums(int L)
{
    LL a[30];
    int mod = 1000000009;
    for(int i = 0; i <= 1040; i ++) {
        c[i][0] = c[i][i] = 1;
        for(int j = 1; j < i; j ++) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
        }
    }
    a[1] = 26;
    LL ans = -1;
    for(int i = 2; i <= 26; ++ i) {
        a[i] = a[i - 1] * (27 - i) % mod;
    }
    if(L <= 26) {
        ans = a[L];
    }
    else {
        ans = a[26];
        int n = 26;
        int m = L - 26 + n;
        ans = ans * c[m - 1][n - 1] % mod;
    }
    ans %= mod;
    int res = (int)ans;
    return res;
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 26; verify_case(0, Arg1, countMinimums(Arg0)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 650; verify_case(1, Arg1, countMinimums(Arg0)); }
	void test_case_2() { int Arg0 = 50; int Arg1 = 488801539; verify_case(2, Arg1, countMinimums(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
StringWeightDiv2 ___test;
___test.run_test(-1);
getch() ;
return 0;
}
// END CUT HERE

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
#define LL long long
typedef long long lint ;
const int maxint = -1u>>2 ;
const double eps = 1e-6 ; 
class MagicalSource
{
public:
long long calculate(long long x)
{
    char s[100];
    sprintf(s, "%lld", x);
    int len = strlen(s);
    LL ans = x;
    LL mod = 0;
    for(int i = 0; i < len; ++ i) {
        mod = mod * 10LL + 1LL;
        if(x % mod == 0)    ans = x / mod;
    }
    return ans;
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 1371110974LL; long long Arg1 = 1234LL; verify_case(0, Arg1, calculate(Arg0)); }
	void test_case_1() { long long Arg0 = 111111LL; long long Arg1 = 1LL; verify_case(1, Arg1, calculate(Arg0)); }
	void test_case_2() { long long Arg0 = 10989LL; long long Arg1 = 99LL; verify_case(2, Arg1, calculate(Arg0)); }
	void test_case_3() { long long Arg0 = 120LL; long long Arg1 = 120LL; verify_case(3, Arg1, calculate(Arg0)); }
	void test_case_4() { long long Arg0 = 109999999989LL; long long Arg1 = 99LL; verify_case(4, Arg1, calculate(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
MagicalSource ___test;
___test.run_test(-1);
getch() ;
return 0;
}
// END CUT HERE

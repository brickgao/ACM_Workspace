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
class TrafficCongestionDivTwo
{
public:
long long theMinCars(int treeHeight)
{
    long long dp[75];
    memset(dp, 0, sizeof(dp));
    dp[1] = 1; dp[2] = 1;
    for(int i = 3; i <= treeHeight + 1; ++ i) {
        for(int j = 1; j <= i - 2; ++ j) {
            dp[i] += dp[j];
        }
        dp[i] *= 2;
        dp[i] += 1;
    }
    return dp[treeHeight + 1];
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; long long Arg1 = 1LL; verify_case(0, Arg1, theMinCars(Arg0)); }
	void test_case_1() { int Arg0 = 2; long long Arg1 = 3LL; verify_case(1, Arg1, theMinCars(Arg0)); }
	void test_case_2() { int Arg0 = 3; long long Arg1 = 5LL; verify_case(2, Arg1, theMinCars(Arg0)); }
	void test_case_3() { int Arg0 = 10; long long Arg1 = 683LL; verify_case(3, Arg1, theMinCars(Arg0)); }
	void test_case_4() { int Arg0 = 60; long long Arg1 = 768614336404564651LL; verify_case(4, Arg1, theMinCars(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
TrafficCongestionDivTwo ___test;
___test.run_test(-1);
getch() ;
return 0;
}
// END CUT HERE

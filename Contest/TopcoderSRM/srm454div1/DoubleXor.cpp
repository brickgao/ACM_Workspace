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
int cal[10][10];
int ten[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};
class DoubleXor
{
public:
int calculate(int N)
{
    for(int i = 0; i <= 9; ++ i)
        for(int j = 0; j <= 9; ++ j)
            cal[i][j] = (i ^ j) % 10;
    int ans = N;
    for(int i = N - 1; i >= 1; -- i) {
        char s1[10], s2[10];
        memset(s1, 0, sizeof(s1));
        memset(s2, 0, sizeof(s2));
        sprintf(s1, "%d", ans);
        sprintf(s2, "%d", i);
        int len1 = (int)strlen(s1);
        int len2 = (int)strlen(s2);
        int maxlen = max(len1, len2);
        int ret = 0;
        int mult = i;
        for(int j = 0; j < maxlen; ++ j) {
            ret *= 10;
            int tmp1 = ans / ten[maxlen - j - 1];
            int tmp2 = mult / ten[maxlen - j - 1];
            ret += cal[tmp1][tmp2];
            ans -= tmp1 * ten[maxlen - j - 1];
            mult -= tmp2 * ten[maxlen - j - 1];
        }
        ans = ret;
    }
    return ans;
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; verify_case(0, Arg1, calculate(Arg0)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 3; verify_case(1, Arg1, calculate(Arg0)); }
	void test_case_2() { int Arg0 = 7; int Arg1 = 0; verify_case(2, Arg1, calculate(Arg0)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 11; verify_case(3, Arg1, calculate(Arg0)); }
	void test_case_4() { int Arg0 = 102; int Arg1 = 103; verify_case(4, Arg1, calculate(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
DoubleXor ___test;
___test.run_test(-1);
getch() ;
return 0;
}
// END CUT HERE

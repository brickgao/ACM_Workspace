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
LL N;

class TheLuckyBasesDivTwo
{
public:

LL count2(LL n) {
    LL cnt = 0;
    for(LL b = 2; b <= n; ++ b) {
        int cdigits = 0;
        LL tmp = n;
        bool luck = true;
        while(tmp > 0) {
            luck = luck && (tmp % b == 4 || tmp % b == 7);
            tmp /= b;
            ++ cdigits;
        }
        if(cdigits <= 2) break;
        if(luck)        ++ cnt;
    }
    return cnt;
}

bool is_lucky(LL n, LL a, LL b) {
    LL tmp = n - b;
    if(tmp % a == 0) {
        if(tmp / a > a && tmp / a > b)      return true;
        else                                return false;
    }
    return false;
}

LL count1(LL n) {
    LL r = 0;
    for(LL a = 4; a <= 7; a += 3)
        for(LL b = 4; b <= 7; b += 3) {
            if(is_lucky(n, a, b))   ++ r;
        }
    return r;
}

LL find(LL n) {
    if(n == 4 || n == 7)    return - 1;
    LL res = 0;
    res += count1(n);
    res += count2(n);
    return res;
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 255LL; long long Arg1 = 1LL; verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { long long Arg0 = 4LL; long long Arg1 = -1LL; verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { long long Arg0 = 13LL; long long Arg1 = 0LL; verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { long long Arg0 = 60LL; long long Arg1 = 2LL; verify_case(3, Arg1, find(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
TheLuckyBasesDivTwo ___test;
___test.run_test(-1);
getch() ;
return 0;
}
// END CUT HERE

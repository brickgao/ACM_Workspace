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
class TeamsSelection
{
public:
string simulate(vector <int> preference1, vector <int> preference2)
{
    int n = SZ(preference1);
    int vis[60];
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < n; ++ i) {
        if(i % 2 == 0) {
            for(int j = 0; j < n; ++ j) {
                if(!vis[preference1[j]]) {
                    vis[preference1[j]] = 1;
                    break;
                }
            }
        }
        else {
            for(int j = 0; j < n; ++ j) {
                if(!vis[preference2[j]]) {
                    vis[preference2[j]] = 2;
                    break;
                }
            }
        }
    }
    string ans = "";
    for(int i = 1; i <= n; ++ i) {
        char tmp = '0' + vis[i];
        ans += tmp;
    }
    return ans;
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2, 3, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "1212"; verify_case(0, Arg2, simulate(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {3, 2, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 3, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "211"; verify_case(1, Arg2, simulate(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {6, 1, 5, 2, 3, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 6, 3, 4, 5, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "212211"; verify_case(2, Arg2, simulate(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {8, 7, 1, 2, 4, 5, 6, 3, 9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7, 2, 4, 8, 1, 5, 9, 6, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "121121212"; verify_case(3, Arg2, simulate(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
TeamsSelection ___test;
___test.run_test(-1);
getch() ;
return 0;
}
// END CUT HERE

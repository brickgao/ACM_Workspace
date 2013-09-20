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
double r[60][60];

class QuickSort
{
public:

double gao(vector <int> L) {
    if(SZ(L) < 2)   return 0;
    double &m = r[*min_element(L.begin(), L.end())][*max_element(L.begin(), L.end())];
    if(m >= 0)  return m;
    double ret = 0;
    for(int i = 0; i < SZ(L); ++ i) {
        vector <int> L1;
        vector <int> L2;
        for(int j = 0; j < SZ(L); ++ j) {
            if(L[j] < L[i]) L1.push_back(L[j]);
            if(L[j] > L[i]) L2.push_back(L[j]);
            if(L[j] < L[i] && j > i)    ret += 1;
            if(L[j] > L[i] && j < i)    ret += 1;
        }
        ret += gao(L1) + gao(L2);
    }
    return m = ret / (double)SZ(L);
}

double getEval(vector <int> L)
{
    vector <int> hash, rec;
    for(int i = 0; i < SZ(L); ++ i)
        for(int j = 0; j < SZ(L); ++ j)
            r[i][j] = -1.0;
    for(int i = 0; i < SZ(L); ++ i) rec.push_back(L[i]);
    sort(rec.begin(), rec.end());
    int k = unique(rec.begin(), rec.end()) - rec.begin();
    for(int i = 0; i < k; ++ i) hash.push_back(rec[i]);
    for(int i = 0; i < SZ(L); ++ i) {
        int pos = lower_bound(hash.begin(), hash.end(), L[i]) - hash.begin();
        L[i] = pos;
    }
    return gao(L);
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.0; verify_case(0, Arg1, getEval(Arg0)); }
	void test_case_1() { int Arr0[] = {1,2,4,3,5,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.0; verify_case(1, Arg1, getEval(Arg0)); }
	void test_case_2() { int Arr0[] = {3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 2.6666666666666665; verify_case(2, Arg1, getEval(Arg0)); }
	void test_case_3() { int Arr0[] = {50,40,30,20,10,15,25,35,45}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 11.07698412698413; verify_case(3, Arg1, getEval(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
QuickSort ___test;
___test.run_test(-1);
getch() ;
return 0;
}
// END CUT HERE

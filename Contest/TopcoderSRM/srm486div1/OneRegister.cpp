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
#include <queue>
using namespace std ;
#define For(i , n) for(int i = 0 ; i < (n) ; ++i)
#define SZ(x)  (int)((x).size())
#define LL long long
typedef long long lint ;
const int maxint = -1u>>2 ;
const double eps = 1e-6 ; 

typedef struct status{
    LL num;
    string s;
} status;

string bfs(int u, int v) {
    bool flag = false;
    queue <status> q;
    status top, tmp;
    if(u > v) {
        tmp.s = "/";
        tmp.num = 1;
        q.push(tmp);
        flag = true;
        if(tmp.num == v)
            return "/";
    }
    else {
        tmp.s = "";
        tmp.num = u;
        q.push(tmp);
    }
    while(!q.empty()) {
        top = q.front();
        q.pop();
        if(top.num != 1) {
            tmp.s = top.s + "*";
            tmp.num = top.num * top.num;
            if(tmp.num == v)  
                return tmp.s;
            else {
                if(tmp.num < v)    q.push(tmp);
            }
        }
        tmp.s = top.s + "+";
        tmp.num = top.num * 2;
        if(tmp.num == v)  
            return tmp.s;
        else {
            if(tmp.num < v)    q.push(tmp);
        }
        if(!flag) {
            flag = true;
            tmp.s = "/";
            tmp.num = 1;
            if(tmp.num == v)  
                return tmp.s;
            else {
                if(tmp.num < v)    q.push(tmp);
            }
        }
    }
    return "^";
}

class OneRegister
{
public:

string getProgram(int s, int t)
{
    if(s == t)  return "";
    string ans = "";
    ans = bfs(s, t);
    if(ans == "^")
        return ":-(";
    else
        return ans;
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 256; string Arg2 = "***"; verify_case(0, Arg2, getProgram(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 7; int Arg1 = 256; string Arg2 = "/+***"; verify_case(1, Arg2, getProgram(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 256; string Arg2 = "**"; verify_case(2, Arg2, getProgram(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 7; int Arg1 = 7; string Arg2 = ""; verify_case(3, Arg2, getProgram(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 3; int Arg1 = 59049; string Arg2 = ":-("; verify_case(4, Arg2, getProgram(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 10; int Arg1 = 1; string Arg2 = "/"; verify_case(5, Arg2, getProgram(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
OneRegister ___test;
___test.run_test(-1);
getch() ;
return 0;
}
// END CUT HERE

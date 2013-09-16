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
int mp2[60][60];
int mp[60][60];
int rec[60][60];
bool vis[60][60];
int n;
const double eps = 1e-6 ; 

int dfs(const int u, const int t) {
    int flag = 0;
    for(int i = 0; i < n; ++ i) {
        if(mp[u][i] == 1) {
            if(mp2[i][t] == 1)  flag |= 1;
            int tmp;
            if(!vis[i][t]) {
                vis[i][t] = true;
                rec[i][t] = tmp = dfs(i, t);
            }
            else
                tmp = rec[i][t];
            if(tmp == 1)
                mp2[i][t] = 0;
            flag |= tmp;
        }
    }
    return flag;
}

class NetworkSecurity
{
public:
int secureNetwork(vector <string> clientCable, vector <string> serverCable)
{
    n = SZ(clientCable);
    memset(mp2, 0, sizeof(mp2));
    memset(mp, 0, sizeof(mp));
    memset(vis, false, sizeof(vis));
    memset(rec, 0, sizeof(rec));
    for(int i = 0; i < SZ(clientCable); ++ i)
        for(int j = 0; j < SZ(clientCable); ++ j)
            if(clientCable[i][j] == 'Y')    mp[i][j] = 1;
            else                            mp[i][j] = 0;
    for(int i = 0; i < SZ(serverCable); ++ i)
        for(int j = 0; j < SZ(serverCable[i]); ++ j)
            if(serverCable[i][j] == 'Y')    mp2[i][j] = 1;
            else                            mp2[i][j] = 0;
    for(int i = 0; i < n; ++ i)
        for(int j = 0; j < n; ++ j)
            for(int k = 0; k < n; ++ k)
                if(mp[i][j] == 1 && mp[j][k] == 1)
                    mp[i][k] = 1;
    for(int i = 0; i < SZ(serverCable); ++ i)
        for(int j = 0; j < SZ(serverCable[i]); ++ j) {
            if(mp2[i][j] == 1 && !vis[i][j]) {
                vis[i][j] = true;
                rec[i][j] = dfs(i, j);
                if(rec[i][j] == 1)
                    mp2[i][j] = 0;
            }
        }
    int ans = 0;
    for(int i = 0; i < SZ(serverCable); ++ i)
        for(int j = 0; j < SZ(serverCable[i]); ++ j) {
            ans += mp2[i][j];
        }
    return ans;
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NYN"
,"NNN"
,"NYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YN"
,"YN"
,"NY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, secureNetwork(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"NN"
,"NN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NNN"
,"NNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, secureNetwork(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"NYNN"
,"NNNN"
,"NNNY"
,"NNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YYN"
,"NNN"
,"NNY"
,"NNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(2, Arg2, secureNetwork(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
NetworkSecurity ___test;
___test.run_test(-1);
getch() ;
return 0;
}
// END CUT HERE

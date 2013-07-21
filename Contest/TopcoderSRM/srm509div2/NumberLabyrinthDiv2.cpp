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
#include <queue>
#include <vector>
using namespace std ;
#define For(i , n) for(int i = 0 ; i < (n) ; ++i)
#define SZ(x)  (int)((x).size())
typedef long long lint ;
const int maxint = -1u>>2 ;
const double eps = 1e-6; 

typedef struct status {
    int x, y, t, k;
} status;

int map[55][55];
int m, n;
int vis[55][55];
int kvis[55][55];
int gx, gy;

class NumberLabyrinthDiv2
{
public:

int bfs(int x1, int y1, int x2, int y2, int k) {
    int mo[4][2];
    queue <status> q;
    status top, tmp;
    tmp.x = x1, tmp.y = y1, tmp.t = 0, tmp.k = k;
    q.push(tmp);
    vis[x1][y1] = 0;
    while(!q.empty()) {
        top = q.front();
        //cout << top.x << " " << top.y << endl;
        q.pop();
        if(map[top.x][top.y] != - 1) {
            if(map[top.x][top.y] == 0)  continue;
            int dis = map[top.x][top.y];
            mo[0][0] = dis, mo[0][1] = 0;
            mo[1][0] = - dis, mo[1][1] = 0;
            mo[2][0] = 0, mo[2][1] = dis;
            mo[3][0] = 0, mo[3][1] = - dis;
            for(int i = 0; i < 4; ++ i) {
                int nx = top.x + mo[i][0];
                int ny = top.y + mo[i][1];
                if(nx < 0 || nx >= m)   continue;
                if(ny < 0 || ny >= n)   continue;
                if(nx == x2 && ny == y2)    return top.t + 1;
                if(map[nx][ny] == 0)    continue;
                if(vis[nx][ny] == -1 || vis[nx][ny] > top.t + 1 || kvis[nx][ny] < top.k) {
                    vis[nx][ny] = top.t + 1;
                    kvis[nx][ny] = top.k;
                    tmp.x = nx, tmp.y = ny, tmp.t = top.t + 1, tmp.k = top.k;
                    q.push(tmp);
                }
            }
        }
        else {
            if(top.k <= 0)  continue;
            for(int dis = 1; dis <= 9; ++ dis) {
                mo[0][0] = dis, mo[0][1] = 0;
                mo[1][0] = - dis, mo[1][1] = 0;
                mo[2][0] = 0, mo[2][1] = dis;
                mo[3][0] = 0, mo[3][1] = - dis;
                for(int i = 0; i < 4; ++ i) {
                    int nx = top.x + mo[i][0];
                    int ny = top.y + mo[i][1];
                    if(nx < 0 || nx >= m)   continue;
                    if(ny < 0 || ny >= n)   continue;
                    if(nx == x2 && ny == y2)    return top.t + 1;
                    if(vis[nx][ny] == -1 || vis[nx][ny] > top.t + 1 || kvis[nx][ny] < top.k - 1) {
                        vis[nx][ny] = top.t + 1;
                        kvis[nx][ny] = top.k - 1;
                        tmp.x = nx, tmp.y = ny, tmp.t = top.t + 1, tmp.k = top.k - 1;
                        q.push(tmp);
                    }
                }
            }
        }
    }
    return -1;
}

int getMinimumNumberOfMoves(vector <string> board, int r1, int c1, int r2, int c2, int K)
{
    m = SZ(board), n = SZ(board[0]);
    gx = r2, gy = c2;
    memset(vis, -1, sizeof(vis));
    memset(kvis, 0, sizeof(kvis));
    for(int i = 0; i < m; ++ i)
        for(int j = 0; j < n; ++ j)
            if(board[i][j] == '.')
                map[i][j] = - 1;
            else
                map[i][j] = board[i][j] - '0';
    vis[r1][c1] = 0;
    int res = bfs(r1, c1, r2, c2, K);
    return int(res);
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"...2",
 "....",
 "3..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; int Arg3 = 2; int Arg4 = 3; int Arg5 = 0; int Arg6 = -1; verify_case(0, Arg6, getMinimumNumberOfMoves(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { string Arr0[] = {"...2",
 "....",
 "3..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; int Arg3 = 2; int Arg4 = 3; int Arg5 = 1; int Arg6 = 2; verify_case(1, Arg6, getMinimumNumberOfMoves(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { string Arr0[] = {"...3",
 "....",
 "2..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; int Arg3 = 2; int Arg4 = 3; int Arg5 = 3; int Arg6 = 3; verify_case(2, Arg6, getMinimumNumberOfMoves(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { string Arr0[] = {"55255",
 ".0.0.",
 "..9..",
 "..3..",
 "3.9.3",
 "44.44"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 2; int Arg3 = 4; int Arg4 = 2; int Arg5 = 10; int Arg6 = 6; verify_case(3, Arg6, getMinimumNumberOfMoves(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_4() { string Arr0[] = {"920909949",
 "900020000",
 "009019039",
 "190299149",
 "999990319",
 "940229120",
 "000409399",
 "999119320",
 "009939999"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; int Arg2 = 3; int Arg3 = 1; int Arg4 = 1; int Arg5 = 50; int Arg6 = 10; verify_case(4, Arg6, getMinimumNumberOfMoves(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
NumberLabyrinthDiv2 ___test;
___test.run_test(-1);
getch() ;
return 0;
}
// END CUT HERE

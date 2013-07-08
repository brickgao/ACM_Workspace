//By Brickgao
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int INF = 1 << 25;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

int t, n, a, b;
vector <int> rec;
int dp[10010];

int main() {
    while(scanf("%d", &t) != EOF) {
        while(t --) {
            rec.clear();
            for(int i = 0; i < 10010; ++ i) dp[i] = 0 - INF;
            scanf("%d%d%d", &n, &a, &b);
            for(int i = 0; i < n; ++ i) {
                int tmp;
                scanf("%d", &tmp);
                if(tmp > 0)
                    rec.push_back(tmp);
            }
//          cout << SZ(rec) << endl;
            sort(rec.begin(), rec.end());
            for(int i = SZ(rec) - 1; i >= 0; -- i) {
                int tmp = INF;
                for(int j = i + 1; j < SZ(rec); ++ j) {
//                  cout << "No." << i << " " << j << endl;
//                  cout << rec[j] - rec[i] << endl;
//                  cout << dp[j] << endl;
                    if(rec[j] - rec[i] >= a && rec[j] - rec[i] <= b && rec[i] - dp[j] <= tmp) {
                        tmp = rec[i] - dp[j];
                    }
                }
                if(tmp == INF)
                    dp[i] = rec[i];
                else
                    dp[i] = tmp;
            }
            int ans = - INF;
            for(int i = 0; i < SZ(rec); ++ i) {
                if(rec[i] >= a && rec[i] <= b)
                    ans = max(ans, dp[i]);
            }
            if(ans == - INF)
                puts("0");
            else
                printf("%d\n", ans);
        }
    }
    return 0;
}


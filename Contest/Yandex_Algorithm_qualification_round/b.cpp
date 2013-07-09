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
const int maxint = -1u>>1;
const int N = 40010;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

bool is[N];
int prm[N]; 
vector <int> ans;
int n, num;

int getprm(int n){ 
    int i, j, k = 0; 
    int s, e = (int )(sqrt(0.0 + n) + 1); 
    memset(is, 1, sizeof(is)); 
    prm[k++] = 2; is[0] = is[1] = 0; 
    for  (i = 4; i < n; i += 2) is[i] = 0; 
    for  (i = 3; i < e; i += 2) if (is[i]) { 
        prm[k++] = i; 
        for  (s = i * 2, j = i * i; j < n; j += s)             
            is[j] = 0; 
    } 
    for  ( ; i < n; i += 2) if (is[i]) prm[k++] = i; 
    return  k;
}


int main() {
    num = getprm(N);
    while(scanf("%d", &n) != EOF) {
        int n2 = n * n;
        ans.clear();
        for(int i = 0; i < num; ++ i) {
            for(int j = i; j < num; ++ j) {
                int tmp = prm[i] * prm[j];
                if(tmp + 1 > n2) break;
                int tmp2 = (int)sqrt(tmp + 1);
                if(tmp2 * tmp2 == tmp + 1)
                    ans.push_back(tmp2);
            }
        }
        sort(ans.begin(), ans.end());
        int k;
        k = unique(ans.begin(), ans.end()) - ans.begin();
        for(int i = 0; i < k; ++ i) {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}


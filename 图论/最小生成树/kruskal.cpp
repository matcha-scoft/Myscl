#include <iostream>
#include <algorithm>
using namespace std;
const int maxm = 100010;
const int maxn = 100010;
int n, m;
int u[maxm], v[maxm], w[maxm];
int r[maxm];
int p[maxn];

int cmp(const int i, const int j) { return w[i] < w[j]; }
int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }   //并查集的查找
int kruskal() {
    int ans = 0;
    for (int i = 0; i < n; i ++) p[i] = i;      //初始化并查集
    for (int i = 0; i < m; i ++) r[i] = i;      //初始化边序号
    sort(r, r + m, cmp);                        //边排序
    for (int i = 0; i < m; i ++) {
        int e = r[i];
        int x = find(u[e]);
        int y = find(v[e]);
        if (x != y) { ans += w[e]; p[x] = y; }
    }
    return ans;
}
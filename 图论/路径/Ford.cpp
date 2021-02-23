#include <iostream>
using namespace std;
const int maxm = 10010;
const int maxn = 10010;
const int INF = 0x3f3f3f3f;

struct edge { int from, to, cost; };        //form到to的边，权值为cost
edge es[maxm];      //边
int d[maxn];        //最短距离
int n, m;           //顶点数，边数

//求解从s出发到所有点的最短距离,O(m * n),无负圈
void shortest_path(int s) {
    for (int i = 0; i < n; i ++) d[i] = INF;
    d[s] = 0;
    while (true) {
        bool update = false;
        for (int i = 0; i < m; i ++) {
            edge e = es[i];
            if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
                update = true;
            }
        }
        if (!update) break;
    }
}
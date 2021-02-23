#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
const int maxn = 100010;
const int INF = 0x3f3f3f3f;
int cost[maxn][maxn];           //e[u][v]的权值
int d[maxn];                    //顶点s出发的最短距离
bool used[maxn];                //已经使用过的图
int n;                          //顶点数

//求从起点s出发到各个顶点的最短距离
//邻接矩阵实现dijkstra，复杂度o(n^2)
//顶点从1到n
void dijkstra(int s) {
    fill(d, d + n + 1, INF);
    fill(used, used + n + 1, false);
    d[s] = 0;
    while (true) {
        int v = -1;
        for (int u = 0; u < n; u ++) {
            if (!used[u] && (v == -1 || d[u] < d[v])) v = u;
        }
        if (v == -1) break;
        used[v] = true;
        for (int u = 0; u < n; u ++) {
            d[u] = min(d[u], d[v] + cost[v][u]);
        }
    }
}

//邻接表实现实用数据结构优化（优先队列）,o(m * logn)
struct edge { int to, cost; };
typedef pair <int, int> P;              //first是最短距离，second是顶点的编号

vector <edge> G[maxn];
void dijkstra_queue(int s) {
    //通过指定参数，优先队列按照first从小到大的顺序
    priority_queue <P, vector <P>, greater <P> > que;
    fill(d, d + n + 1, INF);
    d[s] = 0;
    que.push(P(0, s));

    while (!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        for (int i = 0; i < G[v].size(); i ++) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}


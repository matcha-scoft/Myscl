#include <iostream>
using namespace std;

const int maxn = 1001;
const int INF = 0x3f3f3f3f;
int d[maxn][maxn];          //d[u][v]表示权值
int n;                      //顶点数

//o(v^3),使用dp
void warshall_froyd() {
    for (int k = 0; k < n; k ++) {
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}
#include <iostream>
#include <vector>
using namespace std;
//在 Linux 上，通常的方法是在运行程序前 在终端内 执行 ulimit -s unlimited ，表示栈空间无限。
//每个终端只需执行一次，对之后每次程序运行都有效

//链式前向星
const int maxn = 100;
int vis[maxn];
struct graph {
    typedef vector<int> VI;
    VI info, next, to;
    //初始化图为n个点，m条边
    graph(int n = 0, int m = 0) : to(0), next(0) {
        info.resize(n);
        next.resize(m);
        to.resize(m);
    }
    //返回边的数量
    int edge_size() {
        return to.size();
    }
    //返回值为最大点的编号+1
    int vertex_size() {
        return info.size();
    }
    void expand(int i) {
        if (info.size() < i + 1) info.resize(i + 1);
    }
    //添加一条i到j的边
    void add(int i, int j) {
        expand(i), expand(j);
        to.push_back(j);
        next.push_back(info[i]);
        info[i] = to.size() - 1;
    }
    //删除最后一次添加的边
    void del_back() {
        int i;
        for (i = 0; i < info.size(); i ++) {
            if (info[i] == to.size() - 1) {
                info[i] = next.back();
                break;
            }
            to.pop_back();
            next.pop_back();
        }
    }
    void clear() {
        info.clear();
        next.resize(0);
        to.resize(0);
    }
};
graph tu;

void dfs(int u) {
    cout << u << endl;
    vis[u] = 1;
    for (int i = tu.info[u]; i; i = tu.next[i]) {
        if (!vis[tu.to[i]]) {
            dfs(tu.to[i]);
        }
    }
}
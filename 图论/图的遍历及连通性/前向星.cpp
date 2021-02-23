#include <iostream>
#include <vector>
using namespace std;
/*
    可以保存任意形式的图，常用于网络流
    使用链表存储有向图的边
    info[i]为节点i的边集所对应的链表的头指针，next[j]为第j条边的指向下一条边的指针，to[j]表示第j条边所指向的节点编号。
*/
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
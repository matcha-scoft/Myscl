#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
/*
    结构体：Matrix
    成员变量: 
        int n, m;矩阵大小
        int a[][];矩阵内容
        重载运算符：+ - *
    成员函数：
        void clear()清空矩阵
*/
const int MAXN = 1010;
const int MAXM = 1010;
const double EPS = 1e-6;
struct Matrix {
    int n, m;
    int a[MAXN][MAXM];
    void clear() {
        n = 0;
        m = 0;
        memset(a, 0, sizeof(a));
    }
    Matrix operator + (const Matrix &b) const {
        Matrix temp;
        temp.n = n;
        temp.m = m;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                temp.a[i][j] = a[i][j] + b.a[i][j];
            }
        }
        return temp;
    }
    Matrix operator - (const Matrix &b) const {
        Matrix temp;
        temp.n = n;
        temp.m = m;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                temp.a[i][j] = a[i][j] - b.a[i][j];
            }
        }
        return temp;
    }
    Matrix operator * (const Matrix &b) const {
        Matrix temp;
        temp.clear();
        temp.n = n;
        temp.m = b.m;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < b.m; j ++) {
                for (int k = 0; k < m; k ++) {
                    temp.a[i][j] += a[i][k] * b.a[k][j];
                }
            }
        }
        return temp;
    }
};

/*
    Gauss 消元
    给一个n元一次方程组，求解他们的解集
    说明：将方程组做成矩阵形式， 再利用三种初等矩阵变换，得到上三角矩阵，最后回代得到解集
    接口：int solve(double a[][MAXN], bool l[], double ans[], const int &n);
    复杂度：O(n^3);
    输入：a 方程组对应矩阵
         n 未知数个数
         l，ans 存储解，l代表是否为自由元
    输出：解空间的维数
*/
inline int solve(double a[][MAXN], bool l[], double ans[], const int& n) {
    int res = 0, r = 0;
    for (int i = 0; i < n; i ++) {
        l[i] = false;
    }
    for (int i = 0; i < n; i ++) {
        for (int j = r; j < n; j ++) {
            if (fabs(a[j][i]) > EPS) {
                for (int k = i; k <= n; k ++) {
                    swap(a[j][k], a[r][k]);
                }
                break;
            }
        }
        if (fabs(a[r][i]) < EPS) {
             res ++;
             continue;
        }
        for (int j = 0; j < n; j ++) {
            if (j != r && fabs(a[j][i]) > EPS) {
                double temp = a[j][i] / a[r][i];
                for (int k = i; k <= n; k ++) {
                    a[j][k] -= temp * a[r][k];
                }
            }
        }
        l[i] = true;
        r ++;
    }
    for (int i = 0; i < n; i ++) {
        if (l[i]) {
            for (int j = 0; j < n; j ++) {
                if (fabs(a[j][i]) > 0) {
                    ans[i] = a[j][n] / a[j][i];
                }
            }
        }
    }
    return res;
}

/*
    任务：矩阵的逆
    （A，E） -> (E,A-1)
    接口：void inverse(vector<double> A[], vector<double> C[], int N);
    复杂度：O(n^3)
    输入：A原矩阵
         C逆矩阵
         N矩阵的阶数
*/
inline vector<double> operator * (vector<double> a, double b) {
    int N = a.size();
    vector <double> res(N, 0);
    for (int i = 0; i < N; i ++) {
        res[i] = a[i] * b;
    }
    return res;
}
inline vector<double> operator - (vector<double> a, vector<double> b) {
    int N = a.size();
    vector<double> res(N, 0);
    for (int i = 0; i < N; i ++) {
        res[i] = a[i] - b[i];
    }
    return res;
}
inline void inverse(vector<double> A[], vector<double> C[], int N) {
    for (int i = 0; i < N; i ++) {
        C[i] = vector<double> (N, 0);
        for (int i = 0; i < N; i ++) {
            C[i][i] = 1;
        }
        for (int i = 0; i < N; i ++) {
            for (int j = i; j < N; j ++) {
                if (fabs(A[j][i]) > 0) {
                    swap(A[i], A[j]);
                    swap(C[i], C[j]);
                    break;
                }
            }
            C[i] = C[i] * (1 / A[i][i]);
            A[i] = A[i] * (1 / A[i][i]);
            for (int j = 0; j < N; j ++){
                if (j != i && fabs(A[j][i]) > 0) {
                    C[j] = C[j] - C[i] * A[j][i];
                    A[j] = A[j] - A[i] * A[j][i];
                }
            }
        }
    }
} 

int main() {
    return 0;
}
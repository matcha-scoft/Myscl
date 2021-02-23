/*
    给定a, b, c求a的b次方modc
*/
#include <iostream>
using namespace std;
typedef long long ll;
ll fpow(ll a, ll b, ll c) {
    ll res = 1;
    while (b) {
        if (b & 1) res = (res * a) % c;
        b >>= 1;
        a = (a * a) % c;
    }
    return res;
}
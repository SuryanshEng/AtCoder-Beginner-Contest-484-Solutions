#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
vector<ll> P, T;
ll L, R;
ll SOLVE(int LO, int HI) {
    if (HI - LO <= 1) return 0;
    int MID = (LO + HI) / 2;
    ll C = SOLVE(LO, MID) + SOLVE(MID, HI);
    int A = MID, B = MID;
    for (int I = LO; I < MID; I++) {
        while (A < HI && P[A] - P[I] < L) A++;
        while (B < HI && P[B] - P[I] <= R) B++;
        C += B - A;
    }
    merge(P.begin() + LO, P.begin() + MID, P.begin() + MID, P.begin() + HI, T.begin() + LO);
    copy(T.begin() + LO, T.begin() + HI, P.begin() + LO);
    return C;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> L >> R;
    P.assign(N + 1, 0); T.assign(N + 1, 0);
    for (int I = 1; I <= N; I++) { ll X; cin >> X; P[I] = P[I - 1] + X; }
    cout << SOLVE(0, N + 1);
}
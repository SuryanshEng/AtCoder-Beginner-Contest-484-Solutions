#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
int N, Q, SZ;
vector<int> MN, MX;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> Q;
    SZ = 1;
    while (SZ < N) SZ <<= 1;
    MN.assign(2 * SZ, INF);
    MX.assign(2 * SZ, 0);
    auto SET = [&](int I, int X) {
        if (X == -1) MN[I + SZ] = INF, MX[I + SZ] = 0;
        else MN[I + SZ] = MX[I + SZ] = X;
    };
    for (int I = 0; I < N; I++) { int X; cin >> X; SET(I, X); }
    for (int I = SZ - 1; I >= 1; I--) {
        MN[I] = min(MN[2 * I], MN[2 * I + 1]);
        MX[I] = max(MX[2 * I], MX[2 * I + 1]);
    }
    while (Q--) {
        int T, A, B; cin >> T >> A >> B;
        if (T == 1) {
            int I = A - 1 + SZ;
            SET(A - 1, B);
            for (I >>= 1; I; I >>= 1) {
                MN[I] = min(MN[2 * I], MN[2 * I + 1]);
                MX[I] = max(MX[2 * I], MX[2 * I + 1]);
            }
        } else {
            int LO = INF, HI = 0;
            for (int L = A - 1 + SZ, R = B + SZ; L < R; L >>= 1, R >>= 1) {
                if (L & 1) { LO = min(LO, MN[L]); HI = max(HI, MX[L]); L++; }
                if (R & 1) { --R; LO = min(LO, MN[R]); HI = max(HI, MX[R]); }
            }
            cout << (LO == INF || LO == HI ? "Yes" : "No") << "\n";
        }
    }
}
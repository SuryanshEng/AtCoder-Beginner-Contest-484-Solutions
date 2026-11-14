#include <bits/stdc++.h>
using namespace std;
const int M = 998244353;
int main() {
    string S, X, Y; cin >> S >> X >> Y;
    int LX = X.size(), LY = Y.size(), K = LX + LY;
    auto OK = [](char P, int C) { return P == '?' || P - '0' == C; };
    auto XS = [&](int I) { return I == LX ? 0 : 1 + I; };
    auto YS = [&](int J) { return J == LY ? 1 : LX + J; };
    vector<array<int, 2>> TR(K, {0, 0});
    for (int C = 0; C < 2; C++) {
        for (int St = 0; St < K; St++) {
            int R = 0;
            if (St == 0 || St == 1) {
                if (OK(X[0], C)) R |= 1 << XS(1);
                if (St == 0 && OK(Y[0], C)) R |= 1 << YS(1);
            } else if (St < LX + 1) {
                int I = St - 1;
                if (OK(X[I], C)) R |= 1 << XS(I + 1);
            } else {
                int J = St - LX;
                if (OK(Y[J], C)) R |= 1 << YS(J + 1);
            }
            TR[St][C] = R;
        }
    }
    int F = 1 << K;
    vector<array<int, 2>> NX(F, {-1, -1});
    vector<int> DP(F, 0), ND(F, 0);
    DP[1] = 1;
    for (char CH : S) {
        fill(ND.begin(), ND.end(), 0);
        for (int Mk = 1; Mk < F; Mk++) {
            if (!DP[Mk]) continue;
            for (int C = 0; C < 2; C++) {
                if (CH != '?' && CH - '0' != C) continue;
                int &R = NX[Mk][C];
                if (R < 0) {
                    R = 0;
                    for (int B = 0; B < K; B++) if (Mk >> B & 1) R |= TR[B][C];
                }
                if (R) ND[R] = (ND[R] + DP[Mk]) % M;
            }
        }
        swap(DP, ND);
    }
    long long ANS = 0;
    for (int Mk = 1; Mk < F; Mk++) if (Mk & 3) ANS += DP[Mk];
    cout << ANS % M;
}
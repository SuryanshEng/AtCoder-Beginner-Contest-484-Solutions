#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    vector<int> A(N + 1), C(N + 1, 0);
    for (int I = 1; I <= N; I++) cin >> A[I];
    long long S = 1;
    for (int I = 2; I <= N; I++) {
        if (I >= 3) C[A[I - 2]]++;
        if (A[I] != A[I - 1]) S += (I - 1) - C[A[I]];
    }
    cout << S;
}
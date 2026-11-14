#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    vector<int> A(N), B(N);
    for (int &X : A) cin >> X;
    for (int &X : B) cin >> X;
    int L = 0, R = N - 1;
    while (L < N && A[L] == B[L]) L++;
    if (L == N) { cout << "Yes"; return 0; }
    while (A[R] == B[R]) R--;
    bool OK = B[R] == A[L];
    for (int I = L; OK && I < R; I++) if (A[I + 1] != B[I]) OK = false;
    if (OK) { cout << "Yes"; return 0; }
    OK = B[L] == A[R];
    for (int I = L; OK && I < R; I++) if (A[I] != B[I + 1]) OK = false;
    cout << (OK ? "Yes" : "No");
}
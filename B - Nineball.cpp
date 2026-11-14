#include <bits/stdc++.h>
using namespace std;
int main() {
    int k; cin >> k;
    int m = 10; bool nine = false;
    while (k--) { int x; cin >> x; m = min(m, x); if (x == 9) nine = true; }
    cout << (nine ? m : -1);
}
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    int L, P, V, num = 1;
    cin >> L >> P >> V;
    while(L!=0 && P!=0 && V!=0) {
        cout << "Case " << num++ << ": " << (V / P) * L + min(V % P, L) << '\n';

        cin >> L >> P >> V;
    }

    return 0;
}
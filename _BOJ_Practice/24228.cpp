#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    long long N, R;
    cin >> N >> R;
    cout << (N + 1) + (R - 1) * 2;    
    return 0;
}
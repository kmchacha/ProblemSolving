#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    long long A, B, C;
    cin >> A >> B >> C;
    cout <<  (A+B)%C << '\n';
    cout << ((A%C) + (B%C))%C << '\n';
    cout << (A * B)%C << '\n';
    cout <<  ((A%C) * (B%C))%C;
    return 0;
}
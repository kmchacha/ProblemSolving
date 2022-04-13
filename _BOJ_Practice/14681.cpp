#include <bits/stdc++.h>

using namespace std;

int X, Y;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    cin >> X >> Y;
    if(X > 0 && Y > 0) cout << 1 << '\n';
    else if(X > 0 && Y < 0) cout << 4 << '\n';
    else if(X < 0 && Y > 0) cout << 2 << '\n';
    else cout << 3 << '\n';
    return 0;
}
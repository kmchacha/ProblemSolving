#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    int A, B;
    cin >> A >> B;
    if(A > B) cout << ">";
    else if(A < B) cout << "<";
    else cout << "==";
    return 0;
}
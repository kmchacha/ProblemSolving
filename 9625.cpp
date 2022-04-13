#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    int K, a=1,b=0;
    cin >> K;
    for(int i=1;i<=K;i++){
        int temp = a;
        a = b;
        b = b + temp;
    }
    cout << a << " " << b << '\n';
    return 0;
}
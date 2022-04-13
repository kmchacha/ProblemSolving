#include <bits/stdc++.h>

using namespace std;

long long recur(int n){
    if(n==0) return 1;
    else return recur(n-1) * n;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen("input.txt", "rt", stdin);
    int N;
    cin >> N;
    cout << recur(N);
    return 0;
}
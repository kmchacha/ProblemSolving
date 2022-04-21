#include <bits/stdc++.h>

using namespace std;

int n, k, dp[15][15];
int comb(int a, int b){
    if(dp[a][b] != 0) return dp[a][b];

    if(b == 0) return dp[a][b] = 1;
    else if(b == 1) return dp[a][b] = a;
    else if(a == b) return dp[a][b] = 1;
    else return dp[a][b] = comb(a - 1, b) + comb(a - 1, b - 1);
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    cin >> n >> k;
    cout << comb(n, k);
    return 0;
}
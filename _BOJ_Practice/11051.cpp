#include <bits/stdc++.h>

using namespace std;
// nCr = n-1Cr-1 + n-1Cr

int N, K, dp[1005][1005];
int solve(int n, int r) {
    if(dp[n][r] != -1) return dp[n][r];

    if(r == 0 || n == r) return dp[n][r]=1;
    else if(r == 1) return dp[n][r]=n;
    else return dp[n][r]=(solve(n-1, r-1)%10007 + solve(n-1, r)%10007)%10007;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    memset(dp, -1, sizeof(dp));
    cin >> N >> K;
    cout << solve(N, K) % 10007;
    return 0;   
}
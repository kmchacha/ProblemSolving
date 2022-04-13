#include <bits/stdc++.h>

using namespace std;

const int IMPOSSIBLE = 1000000000;
int N, K, dp[105][10005], coin[105];

// int solve(int n, int k) {
//     if(n == N) return (k > 0 ? 0 : IMPOSSIBLE);
//     if(dp[n][k] != -1) return dp[n][k];

//     int result = solve(n + 1, k);
//     if(k >= coin[n]) result = min(result, solve(n, k-coin[n]) + 1);
//     dp[n][k] = result;
//     return result;
// }
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    memset(dp, -1, sizeof(dp));
    cin >> N >> K;
    for(int i=0;i<N;i++) cin >> coin[i];
    
    for(int i=0;i<=N;i++){
        for(int j=0;j<=K;j++){
            dp[i][j] = IMPOSSIBLE;
        }
    }

    for(int i=0;i<N;i++){
        dp[i][0] = 0;
        for(int j=0;j<=K;j++){
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            int jj = j + coin[i];
            if(jj <= K) dp[i][jj] = min(dp[i][jj], dp[i][j] + 1);
        }
    }
    if(dp[N-1][K] == IMPOSSIBLE) cout << -1;
    else cout << dp[N-1][K];
    return 0;   
}
#include <bits/stdc++.h>

using namespace std;
int dp[1001][3];
int rgb[1001][3];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
    }

    dp[1][0] = rgb[1][0];
    dp[1][1] = rgb[1][1];
    dp[1][2] = rgb[1][2];
    for(int i=2;i<=n;i++){
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + rgb[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + rgb[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + rgb[i][2];
    }
    cout << min(dp[n][0], min(dp[n][1], dp[n][2]));
    return 0;
}

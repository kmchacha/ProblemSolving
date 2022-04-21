#include <bits/stdc++.h>

using namespace std;

int dp[41][2];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("input.txt", "rt", stdin);
    int T, n;
    cin >> T;

    dp[0][0] = 1;
    dp[0][1] = 0;
    dp[1][0] = 0;
    dp[1][1] = 1;

    for(int i=2;i<=40;i++){
        dp[i][0] = dp[i-1][0] + dp[i-2][0];
        dp[i][1] = dp[i-1][1] + dp[i-2][1];
    }
    while(T--){
        cin >> n;
        cout << dp[n][0] << " " << dp[n][1] << '\n';
    }

    return 0;
}
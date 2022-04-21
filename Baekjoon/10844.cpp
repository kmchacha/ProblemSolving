#include <bits/stdc++.h>

using namespace std;

long long dp[101][10];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("input.txt", "rt", stdin);
    int n;
    cin >> n;
    
    // 1 2 3 4 5 6 7 8 9 
    // (10) 12 (21) 23 32 34 43 45 54 56 67 65 76 78 87 (89) 98 
    dp[1][1] = 1; dp[1][2] = 1; dp[1][3] = 1; dp[1][4] = 1; dp[1][5] = 1;
    dp[1][6] = 1; dp[1][7] = 1; dp[1][8] = 1; dp[1][9] = 1;

    for(int i=2;i<=n;i++){
        dp[i][0] = dp[i-1][1];

        dp[i][1] = (dp[i-1][0] + dp[i-1][2])%1000000000;
        dp[i][2] = (dp[i-1][1] + dp[i-1][3])%1000000000;
        dp[i][3] = (dp[i-1][2] + dp[i-1][4])%1000000000;
        dp[i][4] = (dp[i-1][3] + dp[i-1][5])%1000000000;
        dp[i][5] = (dp[i-1][4] + dp[i-1][6])%1000000000;
        dp[i][6] = (dp[i-1][5] + dp[i-1][7])%1000000000;
        dp[i][7] = (dp[i-1][6] + dp[i-1][8])%1000000000;
        dp[i][8] = (dp[i-1][7] + dp[i-1][9])%1000000000;

        dp[i][9] = dp[i-1][8];
    }

    long long cnt=0;
    for(int i=0;i<10;i++){
        cnt += dp[n][i];
        cnt %= 1000000000;
    }

    cout << cnt;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

long long dp[1000001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("input.txt", "rt", stdin);
    int T, n;
    cin >> T;
    dp[0] = 1;
    dp[1] = 1; // 1
    dp[2] = 2; // 1+1, 2
    for(int i=3;i<=1000000;i++){
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % 1000000009;
    }
    while(T--){
        cin >> n;
        cout << dp[n] << '\n';
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int dp[101];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T, n;
    cin >> T;
    dp[0] = 1;
    dp[1] = 1; // 1
    dp[2] = 2; // 1+1, 2
    while(T--){
        cin >> n;
        for(int i=3;i<=n;i++){
            dp[i] = dp[i-1]+ dp[i-2] + dp[i-3];
        }
        cout << dp[n] << '\n';
    }

    return 0;
}
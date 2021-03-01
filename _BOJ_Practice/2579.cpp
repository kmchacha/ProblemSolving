#include <bits/stdc++.h>

using namespace std;

int dp[301][3], arr[301];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("input.txt", "rt", stdin);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }

    dp[1][1] = arr[1];
    for(int i=2;i<=n;i++){
        dp[i][1] = max(dp[i-2][1], dp[i-2][2]) + arr[i];
        dp[i][2] = dp[i-1][1] + arr[i];
    }
    
    cout << max(dp[n][1], dp[n][2]) << '\n';

    return 0;
}
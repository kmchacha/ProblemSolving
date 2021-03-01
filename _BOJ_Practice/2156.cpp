#include <bits/stdc++.h>

using namespace std;

int arr[10001], dp[10001][3]; // i번째까지 최대 마실 수 있는 포도주의 양
// dp[i][0] i 번째 음료를 마시는 경우i 번쨰 음료를 마시지 않는 경우
// dp[i][1] i 번째 음료를 마시는 경우, 연속 1
// dp[i][2] i 번쨰 음료를 마시는 경우, 연속 2

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("input.txt", "rt", stdin);
    int n, ans;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    dp[1][1]= arr[1];
    ans = arr[1];
    for(int i=2;i<=n;i++){
        dp[i][0] = max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2]));
        dp[i][1] = max(dp[i-2][0], max(dp[i-2][1], dp[i-2][2])) + arr[i];
        dp[i][2] = max(dp[i-1][1], dp[i-1][0]) + arr[i];
        //cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << '\n';

        ans = max(ans, dp[i][1]);
        ans = max(ans, dp[i][2]);
        ans = max(ans, dp[i][2]);
    }
    cout << ans;
    return 0;
}

// n이 1인경우도 있으므로 ans는 arr[1]로 초기화를 진행한다
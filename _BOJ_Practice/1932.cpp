#include <bits/stdc++.h>

using namespace std;

int arr[130000], dp[501][501];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("input.txt", "rt", stdin);
    int n, k=0;
    cin >> n;
    k = n * (n+1) / 2;
    for(int i=1;i<=k;i++){
        cin >> arr[i];
    }
    dp[1][1] = arr[1];
    int cnt = 2;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            dp[i][j] = arr[cnt] + max(dp[i-1][j], dp[i-1][j-1]);
            cnt++;
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        ans = max(dp[n][i], ans);
    }
    cout << ans;
    return 0;
}
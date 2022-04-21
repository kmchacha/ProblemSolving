#include <bits/stdc++.h>

using namespace std;

int arr[100001], dp[100001]; 
// dp[i] : i번째가 포함되어서 만들 수 있는 최대 정수

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
    dp[1] = arr[1];
    ans = arr[1];
    for(int i=2;i<=n;i++){
        dp[i] = max(arr[i], dp[i-1] + arr[i]);
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}
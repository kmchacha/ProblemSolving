#include <bits/stdc++.h>

using namespace std;

int arr[1001];
int dp[1001]; // i번째까지 최대 증가하는 부분 수열의 길이
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

    dp[1] = 1;
    ans = 1;
    for(int i=2;i<=n;i++){
        // i번 보다 작은 영역에서 dp[i]는 가장 크면서 arr[i]보다는 작은 값
        int tmp = 0;
        for(int j=1;j<i;j++){
            if(arr[i] > arr[j] && dp[j] > tmp){
                tmp = dp[j];
            }
        }
        dp[i] = tmp + 1;

        ans = max(dp[i], ans);
    }
    cout << ans;
    return 0;
}
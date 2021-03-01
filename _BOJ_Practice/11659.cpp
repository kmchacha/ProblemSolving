#include <bits/stdc++.h>

using namespace std;

int a[100001], dp[100001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("input.txt", "rt", stdin);
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        dp[i] = dp[i-1] + a[i];
    }
    while(m--){
        int a, b;
        cin >> a >> b;
        cout << dp[b] - dp[a-1] << '\n';
    }

    return 0;
}
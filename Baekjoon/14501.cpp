#include <bits/stdc++.h>

using namespace std;

int T[20], P[20];
int dp[20]; // n 일까지 얻는 이익
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "rt", stdin);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)   cin >> T[i] >> P[i];

    // 백준이가 얻을 수 있는 최대 이익을 출력한다.
    for(int i=1;i<=n;i++){
        dp[i] = max(dp[i-1], P[i]);
        cout << dp[i]<< " ";
    }
    return 0;
}
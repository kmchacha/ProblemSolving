#include <bits/stdc++.h>

using namespace std;

int arr[1030][1030], dp[1030][1030];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    int N, M;
    cin >> N >> M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> arr[i][j];
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + arr[i][j];
        }
    }
    for(int i=0;i<M;i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        // cout << dp[x2][y2] << " " <<  dp[x2][y1-1] << " " <<  dp[x1-1][y2] << " " <<  dp[x1-1][y1-1] << '\n';
        cout << dp[x2][y2] - dp[x2][y1-1] - dp[x1-1][y2] + dp[x1-1][y1-1] << '\n';
    }
    return 0;
}
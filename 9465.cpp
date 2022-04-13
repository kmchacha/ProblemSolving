#include <bits/stdc++.h>

using namespace std;

int arr[3][100005];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    int T;
    cin >> T;
    while(T--){
        int N, dp[2][100005];
        cin >> N;
        for(int i=0;i<2;i++){
            for(int j=0;j<N;j++){
                cin >> arr[i][j];
            }
            memset(dp[i], 0, sizeof(int) * N);
        }
        dp[0][0] = arr[0][0];
        dp[1][0] = arr[1][0];

        dp[0][1] = arr[0][1] + dp[1][0];
        dp[1][1] = arr[1][1] + dp[0][0];
        for(int i=2;i<N;i++) {
            dp[1][i] = arr[1][i] + max(dp[0][i-1], dp[0][i-2]);
            dp[0][i] = arr[0][i] + max(dp[1][i-1], dp[1][i-2]);
        }
        int answer = max(dp[0][N-1], dp[1][N-1]);
        cout << answer << '\n';
        
    }
    return 0;
}
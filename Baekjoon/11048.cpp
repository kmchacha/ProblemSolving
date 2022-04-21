#include <bits/stdc++.h>

using namespace std;

int N, M, arr[1005][1005], dp[1005][1005];
int dy[] = {1, 0, 1};
int dx[] = {0, 1, 1};
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    cin >> N >> M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin >> arr[i][j];
            dp[i][j] = arr[i][j];
        }
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            for(int k=0;k<3;k++){
                int nextY = i + dy[k];
                int nextX = j + dx[k];
                if(nextY <= 0 || nextX <= 0 || nextY > N || nextX > M) continue;

                dp[nextY][nextX] = max(dp[nextY][nextX], arr[nextY][nextX] + dp[i][j]);
            }
        }
    }

    // for(int i=1;i<=N;i++){
    //     for(int j=1;j<=M;j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[N][M];
    return 0;
}
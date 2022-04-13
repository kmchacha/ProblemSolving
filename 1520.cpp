#include <bits/stdc++.h>

using namespace std;

int N, M, arr[1005][1005], dp[1005][1005];
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

int dfs(int curY, int curX) {
    if(curY == N-1 && curX == M-1) return 1;
    if(dp[curY][curX] != -1) return dp[curY][curX];

    dp[curY][curX] = 0;
    for(int i=0;i<4;i++){
        int nextY = curY + dy[i];
        int nextX = curX + dx[i];
        if(nextY < 0 || nextX < 0 || nextY >= N || nextX >= M) continue;
        if(arr[curY][curX] > arr[nextY][nextX]) {
            dp[curY][curX] = dp[curY][curX] + dfs(nextY, nextX);
        }
    }
    return dp[curY][curX];
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> arr[i][j];
            dp[i][j] = -1;
        }
    }
    cout << dfs(0, 0);
    return 0;
}
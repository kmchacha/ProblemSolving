#include <bits/stdc++.h>

using namespace std;

//문제는 크게 세가지의 키워드로 분류할 수 있다.
//자두가 떨어지는 T초, 최대 움직일 수 있는 W번, 자두가 위치할 수 있는 위치번호(1, 2번)
int a[2001], dp[3][1005][35];   //dp[자두나무 위치][떨어지는 시간][최대 움직일 수 있는 횟수] = dp[?][T][W]

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int T, W;
    cin >> T >> W;
    for(int i=1;i<=T;i++) cin >> a[i];
    for(int i=1;i<=T;i++){
        for(int j=0;j<=W;j++){
            if(a[i] == 1){
                dp[1][i][j] = max(dp[1][i-1][j] + 1, dp[2][i-1][j-1] + 1);
                dp[2][i][j] = max(dp[1][i-1][j-1], dp[2][i-1][j]);
                //cout << dp[1][i][j] << '\n';
            }else{
                //if(i==1 && j==1) continue;
                dp[1][i][j] = max(dp[1][i-1][j], dp[2][i-1][j-1]);
                dp[2][i][j] = max(dp[1][i-1][j-1] + 1, dp[2][i-1][j] + 1);
                //cout << dp[2][i][j] << '\n';
            }
        }
    }
    int ans = 0;
    for(int i=0;i<=W;i++){
        ans = max(dp[1][T][i], dp[2][T][i]);
    }
    cout << ans;
    return 0;
}
    // dp[0][0] = 0;
    // dp[1][0] = 1;
    // for(int i=1;i<T;i++){
    //     if(dp[i][0] == a[i]) dp[i][0] = dp[i-1][0] + 1;
    //     else dp[i][1] = dp[i-1][0] + 1;
    // }

// 시간 초과 (DFS)
// int T, a[2001], path[2001], ans;
// void DFS(int L, int n, int loc){
//     if(L==T){
//         int cnt = 0;
//         for(int i=0;i<T;i++){
//             if(a[i] == path[i]) cnt++;
//         }

//         if(cnt > ans) ans = cnt;
//     }else if(n==0) {
//         DFS(L+1, n, loc);
//     }else {
//         path[L] = loc;
//         DFS(L+1, n, loc);
//         path[L] = (loc % 2) + 1;
//         DFS(L+1, n-1, loc%2+1);
//     }
// }
// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL); cout.tie(NULL);
//     //freopen("input.txt", "rt", stdin);
//     int W, l=1;
//     cin >> T >> W;
//     for(int i=0;i<T;i++) cin >> a[i];

//     DFS(0, W, l);
//     cout << ans;
//     return 0;
// }
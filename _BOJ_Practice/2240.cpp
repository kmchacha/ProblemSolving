#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int a[2001], dp[2001][2];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int T, W;
    cin >> T >> W;
    for(int i=0;i<T;i++) cin >> a[i];
    dp[0][0] = 0;
    dp[1][0] = 1;
    for(int i=1;i<T;i++){
        if(dp[i][0] == a[i]) dp[i][0] = dp[i-1][0] + 1;
        else dp[i][1] = dp[i-1][0] + 1;
    }
    
    return 0;
}

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
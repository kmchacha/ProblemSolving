/*
'******************************************************************************
' 파일명    : dp11.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/31
' 문제      : 최대 점수 구하기
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int n, m, s, t;
    cin >> n >> m;
    vector<int> dp(m+1);
    for(int i=0;i<n;i++){
        cin >> s >> t;
        for(int j=m;j>=t;j--){
            dp[j]=max(dp[j], dp[j-t]+s);
        }
    }
    cout << dp[m] << '\n';
    return 0;
}
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// int dp[101][1001];
// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     freopen("input.txt", "rt", stdin);
//     int n, m;
//     cin >> n >> m;
//     for(int i=1;i<=n;i++){
//         int s, t;   // score, time
//         cin >> s >> t;


//         for(int k=i;k<=i+1;k++){
//             for(int j=t;j<=m;j++){
//                 dp[k][j] = max(dp[k-1][j-t]+s, dp[k-1][j]);
//             }
//         }
//     }
//     for(int q=0;q<=n;q++){
//         for(int p=0;p<=m;p++){
//             cout << dp[q][p] << " ";
//         }
//         cout << endl;
//     }
//     cout << dp[n][m] << '\n';
//     return 0;
// }
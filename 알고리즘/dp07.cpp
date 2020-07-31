/*
'******************************************************************************
' 파일명    : dp7.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/30
' 문제      : 알리바바와 40인의 도둑(Bottom-up)
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[21][21];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int minn = 2147000000;

            if(i==1) minn=a[i][j-1];
            if(j==1) minn=a[i-1][j];

            if(i-1>=1 && a[i-1][j] && minn>a[i-1][j]){
                minn = a[i-1][j];
            }

            if(j-1>=1 && a[i][j-1]  && minn>a[i][j-1]){
                minn = a[i][j-1];
            }

            a[i][j] += minn;

            //cout << a[i][j] << " ";
        }
        //cout << endl;
    }
    cout << a[n][n] << endl;
    return 0;
}

//dp[0][0]=arr[0][0];
//for(int i=0;i<n;i++){
//     dp[0][i] = dp[0][i-1]+ arr[0][i];
//     dp[i][0] = dp[i-1][0] + arr[i][0];
//}
// for(int i=1;i<n;i++){
//     for(int j=1;j<n;j++){
//         dp[i][j] = min(a[i-1][j], arr[i][j-1]) + arr[i][j];
//     }
// }
//cout << dp[n-1][n-1];
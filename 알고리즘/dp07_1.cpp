/*
'******************************************************************************
' 파일명    : dp7_1.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/30
' 문제      : 알리바바와 40인의 도둑(Top-down) .. return 빼먹지 말기
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[21][21], dp[21][21];
int dfs(int x, int y){
    if(dp[x][y] > 0) return dp[x][y];

    if(x==1 && y==1) return dp[x][y]=a[1][1];
    else {
        if(x==1) return dp[x][y] = dfs(x,y-1) + a[x][y];
        else if(y==1) return dp[x][y] = dfs(x-1,y) + a[x][y];
        else return dp[x][y]=min(dfs(x-1,y), dfs(x,y-1)) + a[x][y];

        //if(a[x-1][y] >= a[x][y-1]) return dp[x][y] = dfs(x,y-1) + a[x][y];
        //else return dp[x][y] = dfs(x-1,y) + a[x][y];
    }
}
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
    cout << dfs(n,n) << endl;
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}
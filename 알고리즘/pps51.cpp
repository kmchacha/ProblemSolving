/*
'******************************************************************************
' 파일명    : pps51.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/21
' 문제      : 영지(territory) 선택 (large)
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[701][701], dp[701][701];
int main(){
    freopen("input.txt", "rt", stdin);
    int h, w, i ,j, n, m, tmp, max=-2147000000;;
    cin >> h >> w;
    for(i=1;i<=h;i++){
        for(j=1;j<=w;j++){
            cin >> a[i][j];
            dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+a[i][j];
        }
    }
    cin >> n >> m;
    for(i=n;i<=h;i++){
        for(j=m;j<=w;j++){
            tmp=dp[i][j]-dp[i-n][j]-dp[i][j-m]+dp[i-n][j-m];
            if(tmp>max) max=tmp;
        }
    }
    cout << max << endl;
    return 0;
}
/*
'******************************************************************************
' 파일명    : pps47.cpp
' 작성자    : 차 경 민
' 목적      : Problem Solving
' 날짜      : 2020/07/21
' 문제      : 봉우리
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[101][101];
int main(){
    //freopen("input.txt", "rt", stdin);
    int n , i, j, cnt=0;
    cin >> n;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin >> a[i][j];
        }
    }

    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(a[i][j]>a[i-1][j] && a[i][j]>a[i+1][j] && a[i][j]>a[i][j+1] && a[i][j]>a[i][j-1]) cnt++;           
        }
    }
    cout << cnt << endl;
    return 0;
}
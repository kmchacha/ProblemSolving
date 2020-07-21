/*
'******************************************************************************
' 파일명    : pps49.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/21
' 문제      : 블록의 최대값
'******************************************************************************
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int a[11][11];
int main(){
    //freopen("input.txt", "rt", stdin);
    int n, i, j, cnt=0;
    cin >> n;
    int * front = new int[n];
    int * right = new int[n];
    for(i=0;i<n;i++){
        cin >> front[i];
    }
    for(i=0;i<n;i++){
        cin >> right[i];
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            a[i][j] = min(front[i],right[j]);
            cnt += a[i][j];
        }
    }
    cout << cnt << endl;
    return 0;
}
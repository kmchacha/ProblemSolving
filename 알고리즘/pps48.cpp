/*
'******************************************************************************
' 파일명    : pps48.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/21
' 문제      : 각 행의 평균과 가장 가까운 값
'******************************************************************************
*/
#include <iostream>
#include <algorithm>    // abs()
#include <vector>
#include <cmath>
using namespace std;
int main(){
    freopen("input.txt", "rt", stdin);
    int a[9][9], i, j, n=9, idx, avg;
    double sum;
    for(i=0;i<n;i++){
        sum = 0;
        for(j=0;j<n;j++){
            cin >> a[i][j];
            sum += a[i][j];
        }
        avg = round(sum/n);         // 0.5 더하고 int화 시키면 첫번째 자리에서 반올림되는 효과...!
        //avg = (sum/9.0) + 0.5;
        idx=0;
        for(j=1;j<n;j++){
            if(abs(a[i][idx]-avg) > abs(a[i][j]-avg)) idx = j;
        }
        cout << avg << " " << a[i][idx] << endl;
    }
    return 0;
}
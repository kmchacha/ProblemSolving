/*
'******************************************************************************
' 파일명    : pps50.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/21
' 문제      : 영지(territory) 선택 (small)
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[51][51];
int main(){
    //freopen("input.txt", "rt", stdin);
    int h, w , i , j , cnt=0, row, col, sum, q, p;
    cin >> h >> w;
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            cin >> a[i][j];
        }
    }
    cin >> col >> row;
    for(i=0;i<=h-col;i++){
        for(j=0;j<=w-row;j++){
            sum = 0;
            for(q=0;q<row;q++){
               for(p=0;p<col;p++){
                   sum += a[i+p][j+q];
               }
            }
            if(cnt < sum) cnt = sum;
        }
    }
    cout << cnt << endl;
    return 0;
}
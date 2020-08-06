/*
'******************************************************************************
' 파일명    : pps23.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/18
' 문제      : 연속 부분 증가수열
'******************************************************************************
*/
#include <iostream>
using namespace std;
int main(){
    //freopen("input.txt", "rt", stdin);
    int n , i, now, pre, max=1, cnt=1;
    cin >> n;
    cin >> pre;
    for(i=1;i<n;i++){
        cin >> now;
        if(pre <= now) {
            cnt++;
            if(max<cnt) max=cnt;
        }
        else cnt = 1;
        pre = now;
    }
    cout << max << endl;
    return 0;
}
/*
'******************************************************************************
' 파일명    : pps.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/18
' 문제      : 석차 구하기
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    //freopen("input.txt", "rt", stdin);
    int n, i, j, cnt=1;
    cin >> n;
    vector<int> a(n), b(n);
    for(i=0;i<n;i++){
        cin >> a[i];
        b[i] = 1;
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(a[i]<a[j]) b[i]++;
        }
    }
    for(i=0;i<n;i++){
        cout << b[i] << " ";
    }
    cout << endl;
    return 0;
}
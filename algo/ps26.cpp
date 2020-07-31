/*
'******************************************************************************
' 파일명    : pps26.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/18
' 문제      : 마라톤
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    //freopen("input.txt", "rt", stdin);
    int n, i, j;
    cin >> n;
    vector<int> a(n), b(n);
    for(i=0;i<n;i++){
        cin >> a[i];
        b[i] = 1;
    }
    for(i=1;i<n;i++){
        for(j=i-1;j>=0;j--){
            if(a[i]<=a[j])   b[i]++;
        }
    }
    for(i=0;i<n;i++){
        cout << b[i] << " ";
    }
    cout << endl;
    return 0;
}
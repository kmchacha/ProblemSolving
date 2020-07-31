/*
'******************************************************************************
' 파일명    : pps22.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/18
' 문제      : 온도의 최대값
'******************************************************************************
*/
#include <iostream>
#include <vector>
using namespace std;
int main(){
    //freopen("input.txt", "rt", stdin);
    int n, k, i, j, max, temp=0;
    cin >> n >> k;
    int* a = (int*)malloc(sizeof(int) * n); // vector<int> a(n);
    for(i=0;i<n;i++){
        cin >> a[i];
    }
    for(i=0;i<k;i++){
        temp += a[i];
    }
    max = temp;
    for(i=0;i<n-k;i++){
        temp += a[i+k];     // temp = temp - a[i] + a[i+k];
        temp -= a[i];
        if(temp > max)  max = temp;
    }
    cout << max << endl;
    free(a);
    return 0;
}
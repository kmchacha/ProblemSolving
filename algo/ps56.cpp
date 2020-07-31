/*
'******************************************************************************
' 파일명    : pps56.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/22
' 문제      : 재귀함수 분석(스택을 이용한 재귀)
'******************************************************************************
*/
#include <iostream>
using namespace std;
void recursion(int n){
    if(n==0)    return;
    else {
        recursion(n-1);
        cout << n << " ";
    }
}
int main(){
    //freopen("input.txt", "rt", stdin);
    int n;
    cin >> n;
    recursion(n);

    return 0;
}
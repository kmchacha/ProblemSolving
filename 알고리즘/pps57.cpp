/*
'******************************************************************************
' 파일명    : pps57.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/22
' 문제      : 재귀함수 이진수 출력
'******************************************************************************
*/
#include <iostream>
using namespace std;
void toBinary(int n){
    if(n==1)    cout << "1";
    else {
        toBinary(n/2);
        cout << n%2;
    }
}
int main(){
    //freopen("input.txt", "rt", stdin);
    int n;
    cin >> n;
    toBinary(n);
    return 0;
}
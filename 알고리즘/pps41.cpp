/*
'******************************************************************************
' 파일명    : pps41.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/20
' 문제      : 연속된 자연수의 합
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    //freopen("input.txt", "rt", stdin);
    int a, i, cnt=0, b=1, tmp;
    cin >> a;
    tmp = a;
    a = a - 1;
    while(a>0){
        b++;
        a = a - b;
        if(a%b==0){
            for(i=1;i<b;i++){
                cout << (a/b)+i<< " + "; 
            }
            cout << (a/b)+i << " = " << tmp << endl;
            cnt++;
        }
    }
    
    return 0;
}
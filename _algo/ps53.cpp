/*
'******************************************************************************
' 파일명    : pps.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/22
' 문제      : K진수 출력 (stack 자료구조 직접 구현)
'******************************************************************************
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>        // => Stack
using namespace std;

int main(){
    //freopen("input.txt", "rt", stdin);
    int n, k;
    stack<int> s;
    char str[20] = "0123456789ABCDEF";
    cin >> n >> k;
    while(1){
        s.push(n%k);
        n = n/k;

        if(n==0) break;
    }
    while(!s.empty()){
        cout << str[s.top()]; // 제일 윗 자료를 참조만.. 끄집어 내지는 않는다.
        s.pop();
    }
    return 0;
}
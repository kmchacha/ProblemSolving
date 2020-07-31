/*
'******************************************************************************
' 파일명    : pps4.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/13
' 문제      : 나이 차이
'
' 문제 설명 : N(2<=ㅜ<=100)명의 나이가 입력됩니다. 이 N명의 사람 중 가장 나이차이가 많이 나는 경우는 몇 살 일까요?
'             최대 나이 차이를 출력하는 프로그램을 작성하세요.
' 출력 설명 : 첫 줄에 최대 나이차이를 출력합니다
' 
'예제
'    10
'    13 15 34 23 45 65 33 11 26 42
'    => 54
'******************************************************************************
*/
#include <iostream>
#include <limits>
using namespace std;
int main(){
    freopen("input.txt", "rt", stdin);
    int n, i, a;
    int min = std::numeric_limits<int>::max();
    int max = std::numeric_limits<int>::min();
    cin >> n;
    for(i=0;i<n;i++){
        cin >> a;
        if(min>a)    min=a;
        if(max<a)    max=a; 
    }
    cout << (max-min) << endl;
    return 0;
}
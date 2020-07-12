/*
'******************************************************************************
' 파일명    : pps2.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/13
' 문제      : 자연수의 합
''
' 문제 설명 : 자연수 A, B가 주어지면 A부터 B까지의 합을 수식과 함께 출력하시오
'
' 출력 설명 : 첫 줄에 더하는 수식과 함꼐 합을 출력한다
' 
'예제
'    3 7
'    => 3 + 4 + 5 + 6 + 7 = 25
'******************************************************************************
*/
#include <iostream>

using namespace std;
int main(){
    int a, b, sum=0;

    cin >> a >> b;

    for(int i=a;i<=b;i++){
        if(i==b) {
            sum += i;
            cout << i << "=" << sum;
            break;
        }
        cout << i << "+";
        sum += i;
    }

    return 0;
}
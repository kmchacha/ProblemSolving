/*
'******************************************************************************
' 파일명    : pps6.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/14
' 문제      : 숫자만 추출
'
' 문제 설명 : ...
'            
' 출력 설명 : 첫 줄에 자연수 출력, 두번째 줄에 약수의 개수 출력
' 
'예제   g0en2Ts8eSoft
'       => 28
'          6
'******************************************************************************
*/
#include <iostream>
#include <string>
using namespace std;
int main(){
    //freopen("input.txt", "rt", stdin);
    string str;
    int i, ans=0, cnt=0;
    cin >> str;
    // 문자열 추출
    for(i=0;i<str.length();i++){    // a[i] != 0x0
        if(str[i]>='0' && str[i]<='9'){
            ans = (ans * 10) + (str[i]-'0');
        }
    }
    // 약수의 개수
    for(i=1;i<=ans;i++){
        if(ans%i==0)    cnt++;
    }
    cout << ans << endl;
    cout << cnt << endl;
    return 0;
}
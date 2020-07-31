/*
'******************************************************************************
' 파일명    : pps7.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/14
' 문제      : 영어단어 복구
'
' 문제 설명 : ...
'            
' 출력 설명 : 첫 줄에 소문자로 된 정상적인 영어단어를 출력한다
' 
'예제   bE  aU T I fu L
'       => beautiful
'******************************************************************************
*/
#include <iostream>
#include <string>
using namespace std;
int main(){
    //freopen("input.txt", "rt", stdin);
    string str;
    int i;
    getline(cin,str);   // gets(a); a-> a[100]
    for(i=0;i<str.length();i++){
        if(str[i]>='a' && str[i]<='z'){
            cout << str[i];
        }else if(str[i]>='A' && str[i]<='Z'){
            cout << (char)(str[i]+32);
        }
    }
    cout << endl;
    return 0;
}
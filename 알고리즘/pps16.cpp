/*
'******************************************************************************
' 파일명    : pps16.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/17
' 문제      : Anagram
'
' 문제 설명 : Anagram이란 두 문자열이 알파벳의 나열 순서는 다르지만, 그 구성이 일치하면 두 단어는 아나그램이라고 한다
'            
' 출력 설명 : 두 단어가 아나그램이면 "YES"를 출력하고, 아니면 "NO"를 출력한다
' 
'예제   AbaAeCe
'      baeeACA
'    => YES
'******************************************************************************
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int a[53];
int b[53];
int main(){
    //freopen("input.txt", "rt", stdin);
    int i;
    string str;
    cin >> str;
    for(i=0;str[i]!=0x0;i++){
        if(str[i] >= 65 && str[i] <= 90){
            a[str[i]-64]++;
        }
        else {
            a[str[i]-70]++;
        }
    }
    cin >> str;
    for(i=0;str[i]!=0x0;i++){
        if(str[i] >= 65 && str[i] <= 90){
            b[str[i]-64]++;
        }
        else {
            b[str[i]-70]++;
        }
    }
    for(i=1;i<=52;i++){
        if(a[i] != b[i]){
            cout << "NO" << endl;
            exit(0);
        }
    }
    cout << "YES" << endl;
    return 0;
}
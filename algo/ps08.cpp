/*
'******************************************************************************
' 파일명    : pps8.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/14
' 문제      : 올바른 괄호
'
' 문제 설명 : 골호가 입력되면 올바른 괄호이면 "Yes", 올바르지 않으면 "NO"를 출력한다
'             (()))() 이것은 괄호의 쌍이 올바르게 위치하는 거지만, 올바른 괄호가 아니다
'            
' 출력 설명 : 첫 번째 줄에 YES, NO를 출력
' 
'예제   (()(()))(())            ()()(()())
'    => NO                      => YES
'******************************************************************************
*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(){
    freopen("input.txt", "rt", stdin);
    
    // 1) Use cnt
    char a[101];
    int i, cnt=0;
    cin >> a;
    for(i=0;a[i]!=0x0;i++){
        if(a[i]=='(')   cnt++;
        else if(a[i]==')') cnt--;
        
        if(cnt<0) break;
    }
    if(cnt==0) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
    
    // 2) Use Stack
    // string str;
    // int i;
    // stack<char> s;
    // cin >> str;
    // for(i=0;str[i]!=0x0;i++){
    //     if(str[i] == '('){
    //         s.push('(');
    //     }else if(str[i] == ')'){
    //         if(s.empty()) {
    //             cout << "NO" << endl;
    //             return 0;
    //         }
    //         s.pop();   
    //     }
    // }
    // if(s.empty()) {
    //      cout << "YES" << endl;
    // }else {
    //     cout << "NO" << endl;
    // }
    // return 0;
}
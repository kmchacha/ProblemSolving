/*
'******************************************************************************
' 파일명    : pps54.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/22
' 문제      : 올바른 괄호(stack)
'******************************************************************************
*/
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
int main(){
    //freopen("input.txt", "rt", stdin);
    char str[31];
    stack<int> s;
    cin >> str;
    for(char *p=str;*p!=0x0;p++){
        if(*p == '('){
            s.push(1);
        }else if(*p == ')'){
            if(s.empty()) {
                cout << "NO" << endl;
                exit(0);
            }
            s.pop();
        }
    }

    if(s.empty()) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
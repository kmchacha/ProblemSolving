/*
'******************************************************************************
' 파일명    : pps27.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/18
' 문제      : N!의 표현법
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    freopen("input.txt", "rt", stdin);
    int n, i, j, tmp;
    cin >> n;
    vector<int> ch(n+1);
    for(i=2; i<=n; i++){
        tmp = i;
        j=2;
        while(1) {
            if(tmp%j==0) {
                tmp = tmp/j;
                ch[j]++;
            }
            else j++;

            if(tmp==1)  break;
        }
    }
    cout << n << "! = ";
    for(i=2;i<=n;i++){
        if(ch[i]!=0)    cout << ch[i] << " ";
    }
    return 0;
}
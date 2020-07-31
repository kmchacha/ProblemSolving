/*
'******************************************************************************
' 파일명    : pps55.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/22
' 문제      : 기차운행(stack응용)
' 출발하는 기차는 무조건 교차로에 들어가야 한다. 교차로는 stack 구조를 가진다
'******************************************************************************
*/
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    //freopen("input.txt", "rt", stdin);
    int n, i, j=1, m;
    stack<int> s;
    cin >> n;
    vector<char> str;
    for(i=1;i<=n;i++){
        cin >> m;
        s.push(m);
        str.push_back('P');
        while(1){
            if(s.empty()) break;
            if(j==s.top()) {
                s.pop();
                j++;
                str.push_back('O');
            }else {
                break;
            }
        }
    }
    if(!s.empty()) cout << "impossible" << endl;
    else {
        for(i=0;i<str.size();i++){
            cout << str[i];
        }

        
        cout << endl;
    }

    return 0;
}

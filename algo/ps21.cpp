/*
'******************************************************************************
' 파일명    : pps21.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/18
' 문제      : 카드 게임
'
' 문제 설명 : 
'            
' 출력 설명 : 
' 
'예제   4 5 6 7 0 1 2 3 9 8 
'       0 1 2 3 4 5 6 7 8 9 
'    => 16 13 
'       A
'******************************************************************************
*/
#include <iostream>
using namespace std;
int main(){
    //freopen("input.txt", "rt", stdin);
    int n=10, i, a[10], b[10], scoreA=0, scoreB=0, flag=0;
    for(i=0;i<n;i++){
        cin >> a[i];
    }
    for(i=0;i<n;i++){
        cin >> b[i];
    }
    for(i=0;i<n;i++){
        if(a[i]>b[i])   {
            scoreA += 3;
            flag = 1;
        }
        else if(a[i]<b[i])  {
            scoreB += 3;
            flag = 2;
        }
        else {
            scoreA += 1;
            scoreB += 1;
        }
    }
    cout << scoreA << " " << scoreB << endl;
    if(scoreA > scoreB) cout << "A" << endl;
    else if(scoreA < scoreB) cout << "B" << endl;
    else {
        if(flag == 0) cout << "D" << endl;
        else if(flag == 1)  cout << "A" << endl;
        else cout << "B" << endl;
    }
    return 0;
}
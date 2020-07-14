/*
'******************************************************************************
' 파일명    : pps37.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/13
' 문제      : Least Recently Used(카카오 캐시 문제 변형)
'
' 문제 설명 : ...
'            
' 출력 설명 : ...
' 
'예제   5 9
'       1 2 3 2 6 2 3 5 7
'    => 7 5 3 2 6
'******************************************************************************
*/
#include <iostream>
using namespace std;
int a[20];
int main(){
    //freopen("input.txt", "rt", stdin);
    int s, n, i, j, k;
    cin >> s >> n;
    for(i=0;i<n;i++){
        cin >> k;
        for(j=0;j<s;j++){
            // Cache Hit
            if(a[j]==k){
                for(int t=j;t>0;t--){
                    a[t] = a[t-1];
                }
                a[0] = k;
                break;
            };
        }
        // Cache Miss
        if(j==s) {
            for(j=s-1;j>0;j--){
                a[j] = a[j-1];
            }
            a[0] = k;
        }
    }
    for(i=0; i<s;i++){
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
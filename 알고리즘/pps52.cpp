/*
'******************************************************************************
' 파일명    : pps52.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/22
' 문제      : Ugly Numbers
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[1501];
int main(){
    //freopen("input.txt", "rt", stdin);
    int n,  i , p2, p3, p5, min=2147000000;
    cin >> n;
    a[1]=1;
    p2=p3=p5=1;
    for(i=2;i<=n;i++){
        if(a[p2]*2 < a[p3]*3) min=a[p2]*2;
        else min = a[p3]*3;
        if(a[p5]*5 < min) min=a[p5]*5;
        
        if(a[p2]*2==min) p2++;
        if(a[p3]*3==min) p3++;
        if(a[p5]*5==min) p5++;
        
        a[i] = min;
    }
    cout << a[n] << endl;
    return 0;
 }
//     int n, i, cnt=0;
//     cin >> n;
//     for(i=1;;i++){
//         int tmp = i;
//         while(1){
//             if(tmp==1) {
//                 cnt++;
//                 break;
//             }

//             if(tmp%2==0) tmp/=2;
//             else if(tmp%3==0) tmp/=3;
//             else if(tmp%5==0) tmp/=5;
//             else break;
//         }
        
//         if(cnt==n) {
//             cout << i << endl;
//             break;
//         }
//     }
/*
'******************************************************************************
' 파일명    : pps62.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/23
' 문제      : 병합 정렬
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[100], tmp[100];
void divide(int left, int right){
    int mid;
    int p1, p2, p3;
    if(left<right){
        mid=(left + right)/2;
        divide(left, mid);
        divide(mid+1, right);
        
        // post order traversal (후위 순회)
        p1 = left;
        p2 = mid+1;
        p3 = left;
        while(p1<=mid && p2<=right){
            if(a[p1] < a[p2]){
                tmp[p3++] = a[p1++];
            }else tmp[p3++] = a[p2++]; 
        }
        while(p1<=mid) tmp[p3++] = a[p1++];
        while(p2<=right) tmp[p3++] = a[p2++];

        for(int i=left;i<=right;i++){
            a[i] = tmp[i];
        }

    }
}
int main(){
    freopen("input.txt", "rt", stdin);
    int n, i;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> a[i];
    }
    divide(0, n-1);
    for(i=0;i<n;i++){
        cout << a[i] << " ";
    }
    return 0;
}
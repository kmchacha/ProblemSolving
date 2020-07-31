/*
'******************************************************************************
' 파일명    : pps42.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/20
' 문제      : 이분 검색
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <algorithm> // sort(), a.push_back()
using namespace std;
int main(){
    //freopen("input.txt", "rt", stdin);
    int n , i , j, target, tmp;
    cin >> n;
    cin >> target;
    vector<int> a(n);
    for(i=0;i<n;i++){
        cin >> a[i];
    }

    // Sort
    sort(a.begin(), a.end());   
    
    // Binary Search
    int lt = 0; // left
    int rt = n-1;   // right
    int mid = (lt+rt)/2;
    while(1){   // lt<=rt 조건도 가능하다, 자료가 발견되지 않을시 멈춘다
        if(a[mid] == target){
            break;
        }else if(a[mid] > target) {
            rt = mid-1;
        }else {
            lt = mid+1;
        }
        mid = (lt + rt) /2;
    }
    cout << mid+1 << endl;
    return 0;
}
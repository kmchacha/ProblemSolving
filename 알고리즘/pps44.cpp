/*
'******************************************************************************
' 파일명    : pps44.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/20
' 문제      : 마구간 정하기 (이분 검색 응용)
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int count(int s, int a[], int n){
    int i, pos=a[1], cnt=1;
    for(i=2;i<=n;i++){
        if(a[i]-pos >= s){
            cnt++;
            pos = a[i];
        }
    }
    return cnt;
}
int main(){
    freopen("input.txt", "rt", stdin);
    int n, m, i, lt=1, rt, mid, res;
    cin >> n >> m;
    int *a = new int[n+1];
    for(i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    rt = a[n];
    while(lt<=rt){
        mid = (lt+rt)/2;
        if(count(mid, a, n) >= m){
            res = m;
            lt = mid + 1;
        }else {
            rt = mid - 1;
        }
    }
    cout << res << endl;
    return 0;
}
/*
'******************************************************************************
' 파일명    : pps84.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/28
' 문제      : 
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, ch[10], maxx=-2147000000, k;
vector<pair<int, int> > arr;
void DFS(int L, int sum){
    if(L==n){
        if(sum>maxx) maxx=sum;
    }
    else{ 
        if(L+arr[L].first <= n) DFS(L+arr[L].first, sum + arr[L].second); // 상담을 하는 경우
        DFS(L+1, sum);  // 상담을 안하는 경우
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "rt", stdin);
    cin >> n;
    for(int i=0;i<n;i++){
        int a, b;
        cin >> a >> b;
        arr.push_back(make_pair(a,b));
    }
    DFS(0,0);
    cout << maxx << endl;
    return 0;
}
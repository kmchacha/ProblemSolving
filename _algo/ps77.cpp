/*
'******************************************************************************
' 파일명    : pps77.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/26
' 문제      : 친구인가? (Disjoint-set : Union & Find 자료구조)
' Disjoint-set(서로소 집합), 교집합이 없는 집합 -> 트리로 구현
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int unf[1001];

int Find(int v){
    if(v==unf[v]) return v;
    else return unf[v]=Find(unf[v]);
}
void Union(int a, int b){
    a=Find(a);
    b=Find(b);
    if(a!=b) unf[a]=b;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int n, m, a, b;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        unf[i]=i;
    }
    for(int i=1;i<=m;i++){
        cin >> a >> b;
        Union(a,b);
    }
    int x, y;
    cin >> x >> y;
    if(Find(x)==Find(y)) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
/*
'******************************************************************************
' 파일명    : pps78.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/26
' 문제      : 원더랜드 Kruskal MST, Union & Find 활용
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int unf[10001];
struct Edge{
    int v1;
    int v2;
    int val;
    Edge(int a, int b, int c){
        v1=a;
        v2=b;
        val=c;
    }
    bool operator<(Edge &b){
        return val<b.val;
    }
};
int Find(int v){
    if(unf[v]==v) return v;
    else return unf[v]=Find(unf[v]);
}
void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a!=b) unf[a]=b;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int v, e, a, b, c, res=0;
    vector<Edge> Ed;
    cin >> v >> e;
    for(int i=1;i<=v;i++){
        unf[i]=i;
    }
    for(int i=1;i<=e;i++){
        cin >> a >> b >> c;
        Ed.push_back(Edge(a,b,c));            
    }
    sort(Ed.begin(), Ed.end());
    for(int i=0;i<e;i++){
        int fa=Find(Ed[i].v1);
        int fb=Find(Ed[i].v2);
        if(fa!=fb){
            res += Ed[i].val;
            Union(Ed[i].v1, Ed[i].v2);
        }       
    }
    cout << res << endl;
    return 0;
}
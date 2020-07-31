/*
'******************************************************************************
' 파일명    : dp13.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/31
' 문제      : 회장 뽑기(플로이드 와샬 알고리즘)
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    int n, score;
    cin >> n;
    vector<vector<int> > dis(n+1, vector<int>(n+1,100));
    vector<int> res(n+1);
    for(int i=1;i<=n;i++) dis[i][i]=0;
    while(1){
        int a, b;
        cin >> a >> b;
        if(a==-1 && b==-1) break;
        dis[a][b]=1;
        dis[b][a]=1;
    }
    // floyed warshall
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dis[i][j]>dis[i][k]+dis[k][j]){
                    dis[i][j]=dis[i][k]+dis[k][j];
                }
            }
        }
    }
    // Print
    score=100;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            res[i]=max(res[i],dis[i][j]);
        }   
        score=min(score, res[i]);
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(res[i]==score) cnt++;
    }
    cout << score << " " << cnt << '\n';
    for(int i=1;i<=n;i++){
        if(res[i]==score) cout << i << " ";
    }
    return 0;
}
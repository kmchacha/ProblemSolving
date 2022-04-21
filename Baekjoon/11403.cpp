#include <bits/stdc++.h>

using namespace std;

int dist[105][105], N;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    cin >> N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> dist[i][j];
        }
    }
    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(dist[i][j] > 0) continue;
                else if(dist[i][k] > 0 && dist[k][j] > 0) {
                    dist[i][j] = 1;
                }
            }
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cout << dist[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}
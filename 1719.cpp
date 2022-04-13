#include <bits/stdc++.h>

using namespace std;

int N, M, path[205][205];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    cin >> N >> M;
    vector<vector<int> > dist(205, vector<int>(205, INT_MAX));
    for(int i=1;i<=N;i++) dist[i][i] = 0;
    for(int i=0;i<M;i++){
        int a, b, time;
        cin >> a >> b >> time;
        dist[a][b] = time;
        dist[b][a] = time;

        path[a][b] = b;
        path[b][a] = a;
    }


    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    if(dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        
                        if(i!=k) path[i][j] = path[i][k];
                    }
                }
            }
        }
    }


    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(path[i][j]) cout << path[i][j] << " ";
            else cout << "- ";
        }
        cout << '\n';
    }
    return 0;
}
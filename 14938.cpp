#include <bits/stdc++.h>

using namespace std;

int N, M, R, score[105];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    cin >> N >> M >> R;
    vector<vector<int> > path(105, vector<int>(105, INT_MAX));
    for(int i=1;i<=N;i++) path[i][i] = 0;
    for(int i=1;i<=N;i++) cin >> score[i];
    for(int i=0;i<R;i++){
        int a, b, l;
        cin >> a >> b >> l;
        path[a][b] = l;
        path[b][a] = l;
    }
    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(path[i][k] !=INT_MAX && path[k][j] != INT_MAX) {
                    path[i][j] = min(path[i][j], path[i][k] + path[k][j]);
                }
            }
        }
    }
    int answer = 0;
    for(int i=1;i<=N;i++){
        int sum = 0;
        for(int j=1;j<=N;j++){
            if(path[i][j] <= M) sum += score[j];
        }
        answer = max(answer, sum);
    }
    cout << answer;
    return 0;
}
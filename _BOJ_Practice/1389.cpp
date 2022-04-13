#include <bits/stdc++.h>

using namespace std;

int N, M, res[105];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    cin >> N >> M;
    vector<vector<int> > rela(105, vector<int>(105, 10000));

    for(int i=0;i<M;i++){
        int a, b;
        cin >> a >> b;
        rela[a][b] = 1;
        rela[b][a] = 1;
    }

    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(rela[i][k] != 10000 &&  rela[k][j] != 10000) rela[i][j] = min(rela[i][j], rela[i][k] + rela[k][j]);

            }
        }
    }

    int temp = INT_MAX;
    for(int i=1;i<=N;i++){
        int sum = 0;
        for(int j=1;j<=N;j++){
            if(i != j) sum += rela[i][j];
        }
        temp = min(sum, temp);
        res[i] = sum;
    }

    for(int i=1;i<=N;i++){
        if(temp == res[i]) {
            cout << i;
            break;
        }
    }

    return 0;
}
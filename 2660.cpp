#include <bits/stdc++.h>

using namespace std;

int N, a, b;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    cin >> N;
    cin >> a >> b;
    vector<vector<int> > rela(55, vector<int>(55, INT_MAX));
    for(int i=1;i<=N;i++) rela[i][i] = 0;
    while(a!=-1 && b!=-1) {
        rela[a][b] = 1;
        rela[b][a] = 1;
        cin >> a >> b;
    }
    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(rela[i][k] != INT_MAX  && rela[k][j] != INT_MAX) {
                    rela[i][j] = min(rela[i][j], rela[i][k] + rela[k][j]);
                }
            }
        }
    }

    vector<int> result(N+1, 0);
    int answer = INT_MAX, count = 0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            result[i] = max(result[i], rela[i][j]);
        }
        if(answer > result[i]) {
            count = 1;
            answer = result[i];
        }else if(answer == result[i]) count++;
    }
    cout << answer << " " << count << '\n';
    for(int i=1;i<=N;i++) {
        if(result[i] == answer) cout << i << " ";
    }
    
    return 0;
}
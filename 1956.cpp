#include <bits/stdc++.h>

using namespace std;

int V, E;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    cin >> V >> E;
    vector<vector<int> > info(405, vector<int>(405, INT_MAX));

    for(int i=0;i<E;i++){
        int a, b, c;
        cin >> a >> b >> c;
        info[a][b] = c;
    }
    for(int k=1;k<=V;k++){
        for(int i=1;i<=V;i++){
            for(int j=1;j<=V;j++){
                if(info[i][k] != INT_MAX && info[k][j] != INT_MAX) info[i][j] = min(info[i][j], info[i][k] + info[k][j]);
            }
        }
    }
    // for(int i=1;i<=V;i++){
    //     for(int j=1;j<=V;j++){
    //         cout << info[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int result = INT_MAX;
    for(int i=1;i<=V;i++){
        for(int j=i+1;j<=V;j++){
            if(info[i][j] != INT_MAX && info[j][i]!=INT_MAX){
                result = min(result, info[i][j] + info[j][i]);
            }
        }
    }

    if(result == INT_MAX) cout << -1;
    else cout << result;

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, map[21][21], ans=2147000000, ch[21];
void DFS(int s, int L){
    if(L==n/2){
        vector<int> start;
        vector<int> link;
        for(int i=1;i<=n;i++){
            if(ch[i]==1) start.push_back(i);
            else link.push_back(i);
        }
        int score_s=0, score_l=0;
        for(int i=0;i<start.size();i++){
            for(int j=i+1;j<start.size();j++){
                int a = start[i], b =start[j];
                int q = link[i], w =link[j];

                score_s += (map[a][b] + map[b][a]);
                score_l += (map[q][w] + map[w][q]);
            }
        }
        ans = min(ans, abs(score_s - score_l));
    }
    else {
        for(int i=s+1;i<=n;i++){
            if(ch[i]==0){
                ch[i]=1;
                DFS(i, L+1);
                ch[i]=0;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> map[i][j];
        }
    }

    DFS(0, 0);
    cout << ans << '\n';

    return 0;
}
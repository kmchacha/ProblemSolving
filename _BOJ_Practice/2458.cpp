#include <iostream>

using namespace std;

int map[501][501];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt","rt",stdin);
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        map[a][b] = 1;
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(map[i][k]==1 && map[k][j]==1) map[i][j]=1;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++){
        int cnt=0;
        for (int j = 1; j <= n; j++){
            if(i==j) continue;

            if(map[i][j]==0 && map[j][i]==0) cnt++;
        }

        if(cnt==0) ans++;
    }
    cout << ans;

    return 0;
}
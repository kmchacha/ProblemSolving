#include <iostream>

using namespace std;

int map[101][101];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("input.txt","rt",stdin);
    int n, m;
    cin >> n;
    cin >> m;
    for(int i=1;i<=m;i++){
        int p1, p2;
        cin >> p1 >> p2;
        map[p1][p2] = 1;
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(map[i][k]==1 && map[k][j]==1) map[i][j]=1;
            }
        }
    }


    for (int i = 1; i <= n; i++){
        int cnt=0;
        for (int j = 1; j <= n; j++){
            if(i==j) continue;

            if(map[i][j]==0 && map[j][i]==0)    cnt++;
        }

        cout << cnt << '\n';
    }

    return 0;
}
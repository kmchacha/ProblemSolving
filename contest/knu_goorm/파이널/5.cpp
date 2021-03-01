#include <bits/stdc++.h>

using namespace std;

char board[15][15];
int ch[15][15];
queue<pair<int, int> > Q;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "rt", stdin);
    int n, cnt=0;
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> board[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(ch[i][j]==0 && board[i][j]=='o'){
                cnt++;
                Q.push(make_pair(i,j));
                ch[i][j]=1;

                while(!Q.empty()){
                    pair<int, int> tmp = Q.front();
                    int cx = tmp.first;
                    int cy = tmp.second;
                    Q.pop();

                    for(int i=0;i<4;i++){
                        int nx = cx + dx[i];
                        int ny = cy + dy[i];

                        if(nx>=1 && ny>=1 && nx<=n && ny<=n && ch[nx][ny]==0){
                            Q.push(make_pair(nx,ny));
                            ch[nx][ny] = 1;
                        }
                    }
                }
            }
        }
    }
    cout << cnt;

    return 0;
}
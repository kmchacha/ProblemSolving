#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int r,c, ans;
char a[30][30], visit[26];
int dx[]={0,1,0,-1};
int dy[]={-1,0,1,0};

void DFS(int x, int y, int cnt){

    ans = max(ans, cnt);

    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx>=1 && ny>=1 && nx<=r && ny<=c){
            if(visit[a[nx][ny]-'A']==0){
                visit[a[nx][ny]-'A'] = 1;
                DFS(nx,ny,cnt+1);
                visit[a[nx][ny]-'A'] = 0;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    cin >> r >> c;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin >> a[i][j];
        }
    }
    visit[a[1][1]-'A']=1;
    DFS(1,1,1);

    cout << ans << '\n';
    return 0;
}
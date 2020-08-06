#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int map[101][101], cnt, ans[101];
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    int m, n, k;
    cin >> m >> n >> k;
    for(int i=0;i<k;i++){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int j=y1;j<y2;j++){
            for(int k=x1;k<x2;k++){
                map[j][k]=1;
            }
        }
    }

    queue<pair<int, int> > Q;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){

            if(map[i][j]==0){
                Q.push(make_pair(i,j));
                int w = 1;
                map[i][j]=1;
                while(!Q.empty()){
                    pair<int, int> tmp = Q.front();
                    Q.pop();
                    for(int k=0;k<4;k++){
                        int xx = tmp.first + dx[k];
                        int yy = tmp.second + dy[k];
                        if(xx>=0 && xx<m && yy>=0 && yy<n){
                            if(map[xx][yy]==0){
                                map[xx][yy]=1;
                                Q.push(make_pair(xx,yy));
                                w++;
                            }
                        }
                    }
                }
                ans[cnt]=w;
                cnt++;
            }
        }
    }
    sort(ans, ans+cnt);
    cout << cnt << '\n';
    for(int i=0;i<cnt;i++){
        cout << ans[i] << " ";
    }

    return 0;
}
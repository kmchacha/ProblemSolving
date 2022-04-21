#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int map[51][51], ch[51][51];
int dx[]={0,1,1,1,0,-1,-1,-1};
int dy[]={1,1,0,-1,-1,-1,0,1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    int w=-1, h=-1;

    cin >> w >> h;
    while(w!=0 && h!=0){
        int cnt=0;
        queue<pair<int, int> > Q;
        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++){
                cin >> map[i][j];
            }
        }
        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++){
                if(ch[i][j]==0 && map[i][j]==1){
                    Q.push(make_pair(i,j));
                    ch[i][j]=1;

                    while(!Q.empty()){
                        pair<int, int> tmp=Q.front();
                        Q.pop();
                        for(int i=0;i<8;i++){
                            int nx= tmp.second + dx[i];
                            int ny= tmp.first + dy[i];
                            if(nx>=1 && ny>=1 && nx<=w && ny<=h && ch[ny][nx]==0 && map[ny][nx]==1){
                                ch[ny][nx]=1;
                                Q.push(make_pair(ny,nx));
                            }
                        }
                    }
                    cnt++;
                }
            }
        }
        // init
        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++){
                ch[i][j]=0;
                map[i][j]=0;
            }
        }
        cout << cnt << '\n';

        cin >> w >> h;

    }
    return 0;
}
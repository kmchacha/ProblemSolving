#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int dx[]={0,1,0,-1};
int dy[]={-1,0,1,0};
int map[21][21], ch[21][21];

struct state{
    int x,y,dis;
    state(int a,int b, int c){
        x=a;
        y=b;
        dis=c;
    }
    bool operator < (const state& bb) const{
        if(dis==bb.dis){
            if(x==bb.x) return y>bb.y;
            else return x>bb.x;
        }else return dis>bb.dis;
    }
};
struct babyShark{
    int x, y, s, ate;
    void sizeUp(){
        ate=0;
        s++;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    int n, res=0;
    babyShark bbshark;
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> map[i][j];
            if(map[i][j]==9) {         
                map[i][j]=0;
                bbshark.x=j;
                bbshark.y=i;
            }
        }
    }

    priority_queue<state> pQ;
    bbshark.ate=0;
    bbshark.s=2;
    pQ.push(state(bbshark.y, bbshark.x, 0));
    while(!pQ.empty()){
        state tmp=pQ.top();
        pQ.pop();
        int x = tmp.y;
        int y = tmp.x;
        int z = tmp.dis;
        // 먹을 수 있는 경우
        if(map[y][x]!=0 && map[y][x]<bbshark.s){
            bbshark.x=x;
            bbshark.y=y;
            bbshark.ate++;
            if(bbshark.ate >= bbshark.s) bbshark.sizeUp();
            map[y][x]=0;
            
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    ch[i][j]=0;
                }
            }
            while(!pQ.empty()) pQ.pop();
            res = tmp.dis;
        }

        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<1 || ny<1 || nx>n || ny>n || map[ny][nx]>bbshark.s || ch[ny][nx]==1) continue;
            ch[ny][nx]=1;
            pQ.push(state(ny, nx, z+1));
        }

    }
    cout << res << '\n';
    return 0;
}
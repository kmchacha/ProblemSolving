#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
char map[201][201];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
queue<pair<int, int> > Q;
int r, c ,n;
void print(){
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cout<<map[i][j];
        }
        cout << '\n';
    }
}
void reset(){
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(map[i][j] == 'O') Q.push(make_pair(i,j));
            else map[i][j] = 'O';
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    //int r, c, n;
    cin >> r >> c >> n;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin >> map[i][j];
            if(map[i][j]=='O') Q.push(make_pair(i,j));
        }
    }
    for(int time=2;time<=n;time++){
        if(time % 2 != 0){
            while(!Q.empty()){
                int cur_x = Q.front().first;
                int cur_y = Q.front().second;
                Q.pop();
                map[cur_x][cur_y] = '.';

                for(int i=0;i<4;i++){
                    int nx = cur_x + dx[i];
                    int ny = cur_y + dy[i];
                    if(nx>=1 && nx<=r && ny>=1 &&ny<=c) {
                        map[nx][ny] = '.';
                    }
                }
            }
        }else {
            reset();
        }

        //print();
    }
    print();
    return 0;
}
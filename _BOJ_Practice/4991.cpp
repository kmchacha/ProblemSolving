#include <bits/stdc++.h>

using namespace std;

char room[25][25];
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
struct loc{
    int x, y, s;
    loc(int a, int b, int c){
        y = a;
        x = b;
        s = c;
    }
    bool operator < (const loc& e) const {
        return s > e.s;
    }
};
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("input.txt", "rt", stdin);
    int w=-1, h=-1;
    while(1){
        int answer = 0;
        cin >> w >> h;
        if(w==0 && h==0) break;

        loc robot(0, 0, 0);
        int dirtyroom = 0;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin >> room[i][j];
                if(room[i][j] == 'o') {
                    robot.y = i;
                    robot.x = j;
                }else if(room[i][j] == '*') dirtyroom++;
            }
        }

        priority_queue<loc> q;
        vector<vector<int> > check(h+1, vector<int>(w+1, 0));
        q.push(loc(robot.y, robot.x, 0));
        check[robot.y][robot.x] = 1;
        while(!q.empty()){
            loc cur = q.top(); q.pop();
            if(room[cur.y][cur.x] == '*') {
                dirtyroom--;
                answer += cur.s;
                if(dirtyroom == 0) break;

                room[cur.y][cur.x] = '.';
                while(!q.empty()) q.pop();

                vector<vector<int> >::iterator iter;
                for(iter = check.begin(); iter != check.end(); iter++){
                    fill(iter->begin(), iter->end(), 0);
                }

                check[cur.y][cur.x] = 1;
                q.push(loc(cur.y, cur.x, 0));
                continue;
            }

            for(int j=0;j<4;j++){
                int nextY = cur.y + dy[j];
                int nextX = cur.x + dx[j];
                if(nextY < 0 || nextX < 0  || nextY >= h || nextX >= w) continue;
                if(room[nextY][nextX] == 'x' || check[nextY][nextX] == 1) continue;
                
                check[nextY][nextX] = 1;
                q.push(loc(nextY, nextX, 1 + cur.s));
            }
        }

        if(answer == 0) cout << -1 << '\n';
        else cout << answer << '\n';
    }    
    return 0;
}
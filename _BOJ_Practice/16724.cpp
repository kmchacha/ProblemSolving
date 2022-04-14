#include <bits/stdc++.h>

using namespace std;

char Board[1005][1005];
int N, M, ch[1005][1005], answer;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> Board[i][j];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(ch[i][j] == 0) {
                answer++;
                queue<pair<int, int> > q;
                q.push(make_pair(i, j));
                while(!q.empty()){
                    pair<int, int> cur = q.front(); q.pop();
                    int curY = cur.first;
                    int curX = cur.second;
                    int nextY, nextX, prevY, prevX;
                    if(Board[curY][curX] == 'D') {
                        nextY = curY + 1;
                        nextX = curX;
                    }else if(Board[curY][curX] == 'R') {
                        nextY = curY;
                        nextX = curX+1;
                    }else if(Board[curY][curX] == 'L') {
                        nextY = curY;
                        nextX = curX-1;
                    }else {
                        nextY = curY-1;
                        nextX = curX;
                    }
                    if(ch[nextY][nextX] == 0) {
                        q.push(make_pair(nextY, nextX));
                        ch[nextY][nextX] = 1;
                    }

                    if(curY-1 >= 0 && Board[curY-1][curX] == 'D' && ch[curY-1][curX] == 0) {
                        q.push(make_pair(curY-1, curX));
                        ch[curY-1][curX] = 1;
                    }
                    if(curX-1 >= 0 && Board[curY][curX-1] == 'R'&& ch[curY][curX-1] == 0) {
                        q.push(make_pair(curY, curX-1));
                        ch[curY][curX-1] = 1;
                    }
                    if(curX+1 < M && Board[curY][curX+1] == 'L'&& ch[curY][curX+1] == 0) {
                        q.push(make_pair(curY, curX+1));
                        ch[curY][curX+1] = 1;
                    }
                    if(curY+1 < N && Board[curY+1][curX] == 'U'&& ch[curY+1][curX] == 0) {
                        q.push(make_pair(curY+1, curX));
                        ch[curY+1][curX] = 1;
                    }
                }
            }
        }
    }
    cout << answer;
    return 0;
}
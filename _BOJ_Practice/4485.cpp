#include <bits/stdc++.h>

using namespace std;

struct link {
    int x, y, rupee;
    link(int a, int b, int c){
        y = a;
        x = b;
        rupee = c;
    }

    bool operator < (const link &b) const {
        return rupee > b.rupee;
    }
};

int N, arr[201][201], cnt, res;
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);

    while(1){
        cin >> N;
        if(N == 0) break;
        cnt++;
        res = INT_MAX;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin >> arr[i][j];
            }
        }

        priority_queue<link> pq;
        vector<vector<int> > ch(N, vector<int>(N, 0));
        pq.push(link(0, 0, arr[0][0]));
        ch[0][0] = 1;
        while(!pq.empty()){
            link cur = pq.top(); pq.pop();

            if(cur.x == N-1 && cur.y == N-1) {
                cout << "Problem " << cnt << ": " << cur.rupee << '\n';
                break;
            }

            for(int i=0;i<4;i++){
                int nextY = dy[i] + cur.y;
                int nextX = dx[i] + cur.x;
                if(nextX < 0 || nextY < 0 || nextX >=N || nextY >= N) continue;
                if(ch[nextY][nextX] == 1) continue;

                ch[nextY][nextX] = 1;
                pq.push(link(nextY, nextX, cur.rupee + arr[nextY][nextX]));
            }
        }
    }
    return 0;
}
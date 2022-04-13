#include <bits/stdc++.h>

using namespace std;

int T, N, V, answer;
int dy[] = {0, 1, -1, 0};
int dx[] = {1, 0, 0, -1};

struct sticker{
    int y, x, value;
    sticker(int a, int b, int c){
        y = a;
        x = b;
        value = c;
    }
    bool operator < (const sticker &s) const{
        return value < s.value;
    }
};
void solve(priority_queue<sticker>& pq){
    vector<vector<int> > ch(2, vector<int>(N, 0));
    while(!pq.empty()){
        sticker s = pq.top(); pq.pop();
        int flag = 0;
        for(int i=0;i<4;i++){
            int nextY = s.y + dy[i];
            int nextX = s.x + dx[i];
            if(nextY < 0 || nextX < 0 || nextY > 1 || nextX >= N) continue;
            if(ch[nextY][nextX] == 1) {flag = 1; break;}
        }
        if(flag == 1) continue;
        ch[s.y][s.x] = 1;
        answer += s.value;
    }
    cout << answer << '\n';
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    cin >> T;
    while(T--){
        cin >> N;
        priority_queue<sticker> pq; answer=0;
        for(int i=0;i<2;i++){
            for(int j=0;j<N;j++){
                cin >> V;
                pq.push(sticker(i, j, V));
            }
        }
        solve(pq);
    }
    return 0;
}
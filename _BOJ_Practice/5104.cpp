#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    int F, S, G, U, D, answer=0;
    cin >> F >> S >> G >> U >> D;
    vector<int> ch(F + 1, 0);
    queue<pair<int, int> > q;
    q.push(make_pair(S, 0));
    ch[S]=1;
    while(!q.empty()){
        pair<int, int> cur = q.front(); q.pop();
        int floor = cur.first;
        int cnt = cur.second;
        if(floor == G) {
            answer = cnt;
            break;
        }
        // cout << floor << " " << cnt << endl;
        if(floor + U <= F && ch[floor + U] == 0) {
            ch[floor + U] = 1;
            q.push(make_pair(floor + U, cnt + 1));
        }
        if(floor - D >= 1 && ch[floor - D] == 0) {
            ch[floor - D] = 1;
            q.push(make_pair(floor - D, cnt + 1));
        }
    }
    if(ch[G] == 0) cout << "use the stairs";
    else cout << answer;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    int N, K;
    cin >> N >> K;
    queue<pair<int, int> > q;
    vector<int> shortpath(100005, INT_MAX);
    q.push(make_pair(N, 0));
    while(!q.empty()){
        int size = q.size();
        int cur = q.front().first; q.pop();
        int curCnt = q.front().second;
        shortpath[cur] = min(shortpath[cur], curCnt);

        if(cur - 1 >= 0) q.push(make_pair(cur - 1, curCnt + 1));
        if(cur + 1 <= 100000) q.push(make_pair(cur + 1, curCnt + 1));
        if(2 * cur <= 100000) q.push(make_pair(cur * 2, curCnt + 1));
    }
    cout << shortpath[K];
    return 0;
}
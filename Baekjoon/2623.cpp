#include <bits/stdc++.h>

using namespace std;

int N, M, degree[1005];
vector<int> graph[1005];
vector<int> answer;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    cin >> N >> M;
    for(int i=0;i<M;i++){
        int cnt, prev, to;
        cin >> cnt;
        cin >> prev;
        for(int j=0;j<cnt-1;j++) {
            cin >> to;
            graph[prev].push_back(to);
            degree[to]++;
            prev = to;
        }
    }

    queue<int> q;
    for(int i=1;i<=N;i++){
        if(degree[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int cur = q.front(); q.pop();
        answer.push_back(cur);
        for(int i=0;i<graph[cur].size();i++){
            int next = graph[cur][i];
            degree[next]--;
            if(degree[next] == 0) q.push(next);
        }
    }

    if(answer.size() == N) {
        for(int i=0;i<N;i++) cout << answer[i] << '\n';
    }else cout << 0;
    return 0;
}
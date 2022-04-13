// 0-1 BFS (https://nicotina04.tistory.com/168)
#include <bits/stdc++.h>

using namespace std;

int N, K;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    cin >> N >> K;
    vector<int> dist(100005, INT_MAX);
    deque<int> dq;
    dq.push_back(N);
    dist[N] = 0;
    while(!dq.empty()){
        int cur = dq.front(); dq.pop_front();
        if(cur == K) {
            cout << dist[K];
            exit(0);
        }

        if(cur + 1 <= 100000 && dist[cur + 1] > dist[cur] + 1) { 
            dist[cur + 1] = dist[cur] + 1;
            dq.push_back(cur + 1); 
        }
        if(cur - 1 >= 0 && dist[cur - 1] > dist[cur] + 1) {  
            dist[cur - 1] = dist[cur] + 1;
            dq.push_back(cur - 1); 
        }
        if(cur * 2 <= 100000 && dist[cur*2] > dist[cur] ) { 
            dist[cur*2] = dist[cur];
            dq.push_front(cur * 2);
        }
    }
    return 0;
}
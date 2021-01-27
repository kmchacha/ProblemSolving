#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

vector<int> map(101), visited(101), dist(101);
queue<int> Q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    
    int l, s;
    cin >> l >> s;
    for(int i=0;i<l+s;i++){
        int x, y;
        cin >> x >> y;
        map[x]=y;
    }

    Q.push(1);
    visited[1]=1;
    while(!Q.empty()){
        int cur = Q.front();
        int tmp = cur;
        Q.pop();
        //cout << cur << endl;
        if(map[cur]>0) cur=map[cur];

        for(int i=1;i<=6;i++){
            int nx = cur + i;
            if(nx>100 || visited[nx]) continue;
            dist[nx] = dist[tmp] + 1;
            visited[nx]=1;
            Q.push(nx);
        }
    }
    // for(int i=0;i<10;i++){
    //     for(int j=0;j<10;j++){
    //         cout << dist[10*i+j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dist[100] << '\n';
    return 0;
}
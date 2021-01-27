#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
vector<int> dis(200001);
int 
main(int argc, const char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    int n, k;
    cin >> n >> k;
    queue<int> Q;
    Q.push(n);
    while(!Q.empty()){
        int cur = Q.front(); 
        Q.pop();
        if(cur == k) break;

        if(cur-1>=0 && dis[cur-1]==0){
            dis[cur-1] = dis[cur] + 1;
            Q.push(cur-1);
        }
        if(cur+1<=100000 && dis[cur+1]==0){
            dis[cur+1] = dis[cur] + 1;
            Q.push(cur+1);
        }
        if(cur*2<=100000 && dis[cur*2]==0){
            dis[cur*2] = dis[cur] + 1;
            Q.push(cur*2);
        }
    }

    cout << dis[k] << '\n';
    return 0;
}
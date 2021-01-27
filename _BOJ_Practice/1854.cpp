#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

// 다익스트라 알고리즘 --> struct, priority queue(pop)
// ******** Heap을 사용하여서 몇번 째 최단경로인지 구하였다
// ******** Heap의 size가 k가 되지 안흐면 -1을 출력하고, Heap의 size가 k이면 가장 위에 있는 top을 출력하였다.
// ******** Heap을 구성할 때에는, 가장 먼저 k개가 있는지 확인한 후, k개가 없으면 무조건 push한다.
// ******** k개의 경로가 존재할 경우, heap의 root노드가 k번째 최단경로가 된다. 이 경로보다 작은 경우에는, 
//          k 번째 경로를 제거하고 넣어준다. 
struct Edge
{
    int vex;
    int dis;
    Edge(int a, int b)
    {
        vex = a;
        dis = b;
    }
    bool operator<(const Edge &b) const
    {
        return dis > b.dis;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int n, m, k; //  n과 m은 각각 여행을 고려하고 있는 도시들의 개수와, 도시 간에 존재하는 도로의 수이다.
    cin >> n >> m >> k;
    vector<pair<int, int> > graph[n + 1];
    priority_queue<Edge> pQ;
    priority_queue<int> paths[n+1];    // MAX HEAP
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
    }
    pQ.push(Edge(1, 0));
    paths[1].push(0);
    while (!pQ.empty())
    {
        int now = pQ.top().vex;
        int cost = pQ.top().dis;
        pQ.pop();

        for (int i = 0; i < graph[now].size(); i++)
        {
            int next = graph[now][i].first;
            int nextDis = graph[now][i].second + cost;
            
            if(paths[next].size() < k) 
                paths[next].push(nextDis);
            else if(paths[next].top() > nextDis){
                paths[next].pop();
                paths[next].push(nextDis);
            }
            else continue;

            pQ.push(Edge(next, nextDis));
            // if (dist[next] > nextDis)
            // {
            //     dist[next] = nextDis;
            //     pQ.push(Edge(next, nextDis));
            // }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        // while(!paths[i].empty()){
		//         cout <<paths[i].top() << " ";
        //         paths[i].pop();
        // }
        // cout << '\n';
        if(paths[i].size() == k) {
            cout << paths[i].top() << '\n';
        }else {
            cout << -1 << '\n';
        }
    }
    return 0;
}

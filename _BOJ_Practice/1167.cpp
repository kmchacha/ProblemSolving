#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> graph[100005];
int N, answer, where;

struct treeInfo
{
    int node, cost;
    treeInfo(int a, int b)
    {
        node = a;
        cost = b;
    }

    bool operator<(const treeInfo &t) const
    {
        return cost < t.cost;
    }
};

void dijkstra(int start)
{
    vector<int> dist(N + 1, INT_MAX);
    priority_queue<treeInfo> pq;
    dist[start] = 0;
    pq.push(treeInfo(start, 0));
    while (!pq.empty())
    {
        treeInfo cur = pq.top();
        pq.pop();

        if(dist[cur.node] < cur.cost) continue;

        for (int j = 0; j < graph[cur.node].size(); j++)
        {
            int next = graph[cur.node][j].first;
            int cost = graph[cur.node][j].second + cur.cost;
            if (dist[next] > cost)
            {
                dist[next] = cost;
                pq.push(treeInfo(next, cost));

                answer = max(answer, dist[next]);
            }
        }
    }
    int temp=0;
    for(int i=1;i<=N;i++) {
        if(dist[i] > temp) {
            temp = dist[i];
            where = i;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int node;
        cin >> node;
        while (1)
        {
            int next, value;
            cin >> next;
            if (next == -1)
                break;
            cin >> value;

            graph[node].push_back(make_pair(next, value));
        }
    }

    dijkstra(1);
    dijkstra(where);

    cout << answer;
    return 0;
}
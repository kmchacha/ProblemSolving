#include <bits/stdc++.h>

using namespace std;

int N, start=10000, starttemp, answer;
vector<pair<int, int> > graph[10005];

void dfs(int node, int curValue, vector<int>& ch){
    int flag = 0;
    for(int i=0;i<graph[node].size();i++){
        int next = graph[node][i].first;
        int value = graph[node][i].second;
        if(ch[next] == 0) {
            ch[next] = 1;
            flag = 1;
            dfs(next, curValue + value, ch);
        }
    }

    if(flag == 0) {
        if(answer < curValue) {
            answer = curValue;
            starttemp = node;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    cin >> N;
    for(int i=0;i<N;i++){
        int parent, child, value;
        cin >> parent >> child >> value;

        start = min(start, parent);
        graph[parent].push_back(make_pair(child, value));
        graph[child].push_back(make_pair(parent, value));
    }

    vector<int> ch1(10005, 0);
    vector<int> ch2(10005, 0);
    ch1[start] = 1;
    dfs(start, 0, ch1);

    ch2[starttemp] = 1;
    dfs(starttemp, 0, ch2);

    cout << answer;
    return 0;
}
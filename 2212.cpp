#include <bits/stdc++.h>

using namespace std;

int N, K, arr[10005], dist[10005], sum;

bool cmp(int n1, int n2) {
    return n1 > n2;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    cin >> N >> K;
    for(int i=0;i<N;i++) cin >> arr[i];
    sort(arr, arr + N);
    for(int i=0;i<N-1;i++) dist[i] = arr[i+1] - arr[i];
    sort(dist, dist + N - 1, cmp);
    sum = arr[N-1] - arr[0];
    for(int i=0;i<K-1;i++) sum -= dist[i];
    cout << sum;
    return 0;
}
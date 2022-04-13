#include <bits/stdc++.h>

using namespace std;

int N, dplength[105];
vector<pair<int, int> > v;
bool compare(pair<int, int>& p1, pair<int, int>& p2){
    if(p1.first != p2.first) return p1.first < p2.first;
    else return p1.second < p2.second;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    cin >> N;
    for(int i=0;i<N;i++) {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
        dplength[i]=1;
    }
    sort(v.begin(), v.end(), compare);
    for(int i=1;i<N;i++){
        for(int j=i-1;j>=0;j--){
            if(v[i].second > v[j].second) dplength[i] = max(dplength[i], dplength[j] + 1);
        }
    }
    int temp = 0;
    for(int i=0;i<N;i++) temp = max(temp, dplength[i]);
    cout << N - temp;
    return 0;
}
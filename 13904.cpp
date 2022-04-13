#include <bits/stdc++.h>

using namespace std;

int N, answer, reserv[1005];
vector<pair<int, int> > v;
bool compare(pair<int, int> &p1, pair<int, int> &p2) {
    if(p1.second != p2.second) return p1.second > p2.second;
    else return p1.first > p2.first;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    cin >> N;
    for(int i=0;i<N;i++) {
        int d, w;
        cin >> d >> w;
        v.push_back(make_pair(d, w));
    }
    sort(v.begin(), v.end(), compare);
    for(int i=0;i<N;i++){
        int d = v[i].first;
        int w = v[i].second;
        for(int j=d;j>=1;j--){
            if(reserv[j] == 0) {
                reserv[j] = w;
                break;
            }
        }
    }
    for(int i=1;i<=1000;i++)  answer += reserv[i];
    cout << answer;
    return 0;
}
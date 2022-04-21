#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("input.txt", "rt", stdin);
    int N, M , cnt=0;
    unordered_map<string, int> hashMap;
    cin >> N >> M;
    string temp;
    for(int i=0;i<N;i++) {
        cin >> temp;
        hashMap[temp]++;
    }
    vector<string> q;
    for(int i=0;i<M;i++){
        cin >> temp;
        if(hashMap[temp] != 0) {
            cnt++;
            q.push_back(temp);
        }
    }
    cout << cnt << '\n';
    sort(q.begin(), q.end());

    for(int i=0;i<q.size();i++){
        cout << q[i] << '\n';
    }
    
    return 0;
}
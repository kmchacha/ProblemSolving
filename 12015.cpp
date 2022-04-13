#include <bits/stdc++.h>

using namespace std;

int updp[1000005], answer, x;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    int N;
    cin >> N;
    vector<int> v;
    for(int i=0;i<N;i++){
        cin >> x;

        if(v.empty() || v.back() < x) {
            v.push_back(x);
            updp[i] = v.size();
        }else {
            int idx =  lower_bound(v.begin(), v.end(), x) - v.begin();
            v[idx] = x;
            updp[i] = idx + 1;
        }
    }
    for(int i=0;i<N;i++) answer = max(answer, updp[i]);
    cout << answer;
    return 0;
}
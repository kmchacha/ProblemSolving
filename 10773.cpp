#include <bits/stdc++.h>

using namespace std;

int N;
stack<int> s;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    cin >> N;
    for(int i=0;i<N;i++) {
        int x;
        cin >> x;
        if(x == 0) s.pop();
        else s.push(x);
    }
    int sum = 0;
    while(!s.empty()) {
        sum += s.top(); s.pop();
    }
    cout << sum;
    return 0;
}
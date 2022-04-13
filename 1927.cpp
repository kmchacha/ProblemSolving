#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen("input.txt", "rt", stdin);
    priority_queue<int, vector<int>, greater<int> > pQ;
    int N, input;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> input;
        if(input==0) {
            if(pQ.empty()) cout << 0 << '\n';
            else {
                cout << pQ.top() << '\n';
                pQ.pop();
            }
        }else pQ.push(input);
    }

    return 0;
}
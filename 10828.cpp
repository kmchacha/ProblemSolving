#include <bits/stdc++.h>

using namespace std;

int N, number;
stack<int> s;
string str;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> str;
        if(str == "push") {
            cin >> number;
            s.push(number);
        }else if(str == "top") {
            if(!s.empty()) cout << s.top() << '\n';
            else cout << -1 << '\n';
        }
        else if(str == "size") cout << s.size() << '\n';
        else if(str == "empty") cout << s.empty() << '\n';
        else if(str == "pop") {
            if(!s.empty()) {
                cout << s.top() << '\n';
                s.pop();
            }else cout << -1 << '\n';
        }

    }
    return 0;
}
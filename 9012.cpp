#include <bits/stdc++.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    int T;
    cin >> T;
    while(T--) {
        stack<int> s;

        string str;
        cin >> str;
        for(int i=0;i<str.size();i++) {
            if(str[i] == ')' && s.empty()) {s.push(-1); break;}
            else if(str[i] == '(') s.push(str[i]);
            else s.pop();
        }

        if(!s.empty()) cout << "NO" << '\n';
        else cout << "YES" << '\n';
    }
    return 0;
}
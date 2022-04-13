#include <bits/stdc++.h>

using namespace std;

int N, number;
deque<int> dq;
string str;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> str;
        if(str == "push_back") {
            cin >> number;
            dq.push_back(number);
        }else if(str == "push_front") {
            cin >> number;
            dq.push_front(number);
        }else if(str == "front") {
            if(!dq.empty()) cout << dq.front() << '\n';
            else cout << -1 << '\n';
        }
        else if(str == "back") {
            if(!dq.empty()) cout << dq.back() << '\n';
            else cout << -1 << '\n';
        }
        else if(str == "size") cout << dq.size() << '\n';
        else if(str == "empty") cout << dq.empty() << '\n';
        else if(str == "pop_front") {
            if(!dq.empty()) {
                cout << dq.front() << '\n';
                dq.pop_front();
            }else cout << -1 << '\n';
        }else if(str == "pop_back") {
            if(!dq.empty()) {
                cout << dq.back() << '\n';
                dq.pop_back();
            }else cout << -1 << '\n';
        }else cout << "?" << endl;

    }
    return 0;
}
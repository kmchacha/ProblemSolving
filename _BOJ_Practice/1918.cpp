#include <bits/stdc++.h>

using namespace std;

string answer, str;
stack<char> s;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    cin >> str;
    for(int i=0;i<str.size();i++){
        if('A' <= str[i] && str[i] <= 'Z') {
            answer += str[i];
            continue;
        }

        if(str[i] == '(') {
            s.push(str[i]);
            continue;
        }

        if(str[i] == ')') {
            while(s.top() != '(') {
                answer += s.top();
                s.pop();
            }
            s.pop();
            continue;
        }

        if(str[i] == '*' || str[i] == '/') {
            while(!s.empty() && (s.top() == '*' || s.top() == '/')) {
                answer += s.top();
                s.pop();
            }
        }else {
            while(!s.empty() && s.top() != '(') {
                answer += s.top();
                s.pop();
            }
        }
        s.push(str[i]);
    }

    while(!s.empty()) {
        answer += s.top();
        s.pop();
    }
    cout << answer;
    return 0;
}
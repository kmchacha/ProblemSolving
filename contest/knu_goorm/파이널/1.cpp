#include <bits/stdc++.h>

using namespace std;

string s[1001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("input.txt", "rt", stdin);
    int n;
    string str;
    cin >> str >> n;
    for(int i=1;i<=n;i++){
        cin >> s[i];
    }

    int flag = 0;
    for(int i=1;i<=n;i++){
        if(s[i] == str) {
            flag = i;
            break;
        }
    }
    if(flag==0) cout << "-1" << '\n';
    else cout << flag << '\n';

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

char str[105];
int N, answer;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++) cin >> str[i];
    for(int i=0;i<N;i++) answer += (str[i] - '0');
    cout << answer;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int answer;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N;
    cin >> N;
    for(int i=1;i<=N;i++) answer += i;
    cout << answer;
    return 0;
}
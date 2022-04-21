#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> v;
bool compare(int a, int b){
    return a > b;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    cin >> N;
    while(N > 0) {
        v.push_back(N % 10);

        N = N / 10;
    }
    sort(v.begin(), v.end(), compare);
    for(int i=0;i<v.size();i++) cout << v[i];
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

map<long long, long long> memo;

long long fibo(int n){
    if(memo[n] > 0) return memo[n];

    if(n==0) return memo[n] = 0;
    else if(n==1) return memo[n] = 1;
    else return memo[n] = ((fibo(n-1) % 1000000007) + (fibo(n-2) % 1000000007)) % 1000000007 ;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen("input.txt", "rt", stdin);
    long long N;
    cin >> N;
    cout << fibo(N % 1000000007);
    return 0;
}
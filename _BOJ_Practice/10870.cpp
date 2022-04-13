#include <bits/stdc++.h>

using namespace std;

long long fibonacci(int n){
    if(n==0) return 0;
    else if(n==1) return 1;
    else return (fibonacci(n-1) + fibonacci(n-2));
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    cout << fibonacci(n);
    return 0;
}
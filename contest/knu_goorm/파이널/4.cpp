#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("input.txt", "rt", stdin);
    int n;
    cin >> n;
    while(n >= 10){
        int num = n, sum=0;
        while(1){
            sum += (num % 10);
            num = num / 10;
            if(num < 10) break;

        }
        sum += num;
        n = sum;   
    }
    
    if(n%2==0) cout << n << " " << "even"<< '\n';
    else cout << n << " " << "odd" << '\n';
    
    return 0;
}
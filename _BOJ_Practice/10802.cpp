#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    string a, b;
    long long cnt=0;
    cin >> a >> b;
    for(long long i=stol(a);i<=stol(b);i++){
        int tmp = i;
        int flag=0;
        while(tmp>0){
            if(tmp % 10 == 3 || tmp % 10 == 6 || tmp %10 == 9) { cnt++;  flag=1; break;}
            tmp = tmp / 10;
        }

        if(flag==1) continue;

        if(i%3==0) cnt++;
    }
    cout << cnt%20150523 << '\n';
    return 0;
}
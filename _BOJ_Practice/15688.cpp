#include <iostream>
#include <algorithm>

using namespace std;


int freq[2000001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("input.txt", "rt", stdin);
    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        freq[a+1000000]++;
    }
    for(int i=0;i<=2000000;i++){
        while(freq[i]>0){
            cout << i-1000000 << '\n';
            freq[i]--;
        }
    }

    return 0;
}
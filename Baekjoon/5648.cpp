#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

long long arr[1000001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("input.txt", "rt", stdin);
    int n;
    string str;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> str;
        long long value = str[0]-'0'; long long ten=10;
        for(int j=1;j<str.length();j++){
            value = value + (str[j]-'0')*ten;
            ten *= 10;
        }
        arr[i] = value;
    }
    sort(arr, arr+n);
    for(int i=0;i<n;i++) cout << arr[i] << '\n';
    return 0;   
}
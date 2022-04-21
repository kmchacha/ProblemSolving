#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

void DFS(int a, int b){
    
}
// d1 d2 d3 d4 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    // D n을 두배로 바꾼다 ((2 * n) % 10000)
    // S n-1        1~9999 (if n==0 to 9999)
    // L 왼쪽 회전  n%1000 <<1 + n/1000
    // R 오른쪽 회전

    int n = 1234;
    cout << n << endl;
    cout << ((n%1000)*10)+n/1000 << endl;
    cout << (n/10) + ((((n%1000)%100)%10)*1000) << endl;
    int a=1234, b = 3412;
    DFS(a, b);

    return 0;
}
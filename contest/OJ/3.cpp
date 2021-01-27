#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    int n, m;
    cin >> n >> m;  // n 과 m 은 서로소
    for(int i=1;i<=100;i++){
        if(i%n==0 && i%m==0){
            cout << "PichiSet"<<'\n';
        }else if(i%n==0){
            cout << "Pizza" << '\n';
        }else if(i%m==0){
            cout << "Chicken" << '\n';
        }else {
            cout << i << '\n';
        }
    }

    return 0;
}

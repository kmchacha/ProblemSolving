#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    int input;
    while (cin>>input) {
		if (input % 6) cout<<"N\n";
		else cout<<"Y\n";
	}
    
    return 0;
}
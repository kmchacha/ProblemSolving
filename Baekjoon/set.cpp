#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
multiset<int> s;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "rt", stdin);
    for(int i=0;i<9;i++){
        int x;
        cin >> x;
        s.insert(x);
    }
    s.insert(3);
    multiset<int>::iterator iter;
    //s.erase(--s.end());
    s.erase(s.begin()--);
    for(iter=s.begin();iter!=s.end();iter++){
        cout << *iter << endl;
    }
    cout << s.count(1) << endl;
    if(s.find(3)==s.end()) cout << "1" << endl;
    else cout << "2" << endl;
    
    return 0;
}
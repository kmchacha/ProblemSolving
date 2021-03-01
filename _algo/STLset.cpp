#include <bits/stdc++.h>
using namespace std;

// set은 중복한 것을 제거하는 용도로 사용한다
int main(){
    int a[10]={1,3,2,3,2,3,2,3,1,2};
    set<int> s; // 군형잡힌 이진트리(레드 블랙 트리)
    s.insert(3); // insert 호출시 자동으로 정렬이 된다 (중복 x)
    for(int i=0;i<10;i++){
        s.insert(a[i]);
    }
    cout << s.size() << endl;
    // for(auto it=s.begin(); it != s.end(); it++){
    //     cout << *it << " ";
    // }

    for(auto x : s) cout << x << " ";
    cout << endl;
    
    if(s.find(3) == s.end()) cout <<  "false" << endl;
    else cout << "true" << endl;
    
    if(s.find(8) == s.end()) cout <<  "false" << endl;
    else cout << "true" << endl;

    return 0;
}

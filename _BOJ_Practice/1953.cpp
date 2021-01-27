#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
using namespace std;

queue<pair<int, int> > Q;

set<int> s1, s2;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int size, a;
        cin >> size;
        for(int j=1;j<=size;j++){
            cin >> a;
            Q.push(make_pair(i, a));
        }
    }
    set<int>::iterator iter;
    s1.insert(1);

    while(!Q.empty()){
        pair<int, int> tmp = Q.front();
        Q.pop();
        int a = tmp.first;
        int b = tmp.second;
        int flag=0;
        for(iter=s1.begin();iter!=s1.end();iter++){
            if(a == *iter && flag==0){
                s2.insert(b);
                flag=1;
                break;
            }
        }
        for(iter=s1.begin();iter!=s1.end();iter++){
            if(b == *iter && flag==0){
                s2.insert(a);
                flag=1;
                break;
            }
        }
        for(iter=s2.begin();iter!=s2.end();iter++){
            if(a == *iter && flag==0){
                s1.insert(b);
                flag=1;
                break;
            }
        }
        for(iter=s2.begin();iter!=s2.end();iter++){
            if(b == *iter && flag==0){
                s1.insert(a);
                flag=1;
                break;
            }
        }
        if(flag==0) {
            s1.insert(a);
            s2.insert(b);
        }
    }
    cout << s1.size() << '\n';
    for(iter=s1.begin();iter!=s1.end();iter++){
        cout << *iter << " ";
    }
    cout << '\n';
    cout << s2.size() << '\n';
    for(iter=s2.begin();iter!=s2.end();iter++){
        cout << *iter << " ";
    }
    return 0;
}
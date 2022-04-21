#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
multiset<long long> s;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    int testcase;
    cin >> testcase;
    for(int i=0;i<testcase;i++){
        int n;
        cin >> n;
        for(int j=0;j<n;j++){
            char c;
            long long num;
            cin >> c >> num;
            if(c=='I') {
                s.insert(num);
            }
            else if(c=='D'){
                multiset<long long>::iterator iter;
                if(s.empty()) continue;

                if(num==1){
                    s.erase(--s.end());
                }
                else if(num==-1){
                    s.erase(s.begin());
                }

             }
        }
        if(s.empty()) {
            cout << "EMPTY" << '\n';
        }
        else {
            cout << *(--s.end()) << " " << *s.begin() << '\n';
            s.clear();
        }
    }
    return 0;
}
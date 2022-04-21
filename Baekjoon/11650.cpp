#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.first > b.first) return false;
    else if(a.first < b.first) return true;
    else {
        if(a.second > b.second) return false;
        else return true;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt","rt",stdin);
    int n;
    cin >> n;
    vector<pair<int, int> > arr(n+1, make_pair(0,0));
    for(int i=1;i<=n;i++){
        int a, b;
        cin >> a >> b;
        arr[i].first = a;
        arr[i].second = b;
    }
    sort(arr.begin()+1, arr.begin()+n+1, compare);
    for(int i=1;i<=n;i++){
        cout << arr[i].first << " " << arr[i].second <<'\n';
    }
    return 0;
}
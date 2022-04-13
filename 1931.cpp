#include <bits/stdc++.h>

using namespace std;

struct my_time{
    int st, et;
    my_time(int a,int b){
        st = a;
        et = b;
    }
    bool operator < (const my_time &t) const {
        if(et != t.et) return et < t.et;
        else return st < t.st;
    }
};
int N, answer;
vector<my_time> arr;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    cin >> N;
    for(int i=0;i<N;i++){
        int a, b;
        cin >> a >> b;
        arr.push_back(my_time(a, b));
    }
    sort(arr.begin(), arr.end());
    int rt = 0;
    for(int i=0;i<N;i++){
        if(rt > arr[i].st) continue;
        answer++;
        rt = arr[i].et;
    }
    cout << answer;
    return 0;
}
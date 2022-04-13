#include <bits/stdc++.h>

using namespace std;

long long arr[100005], N;
long long recursion(long long s, long long e){
    if(s > e) return 0;
    if(s == e) return arr[s] * arr[s];

    long long mid = (s + e) / 2;
    long long result = max(recursion(s, mid), recursion(mid + 1, e));

    long long lt = mid, rt = mid, sum = arr[mid], minvalue = arr[mid];
    while(rt - lt < e - s){
        long long p = (rt < e) ? arr[rt + 1] : -1;
        long long q = (s < lt) ? arr[lt - 1] : -1;

        if(p >= q) {
            sum += p;
            minvalue = min(minvalue, p);
            rt += 1;
        }else { 
            sum += q;
            minvalue = min(minvalue, q);
            lt -= 1;
        }

        result = max(result, sum * minvalue);
    }
    return result;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    cin >> N;
    for(int i=0;i<N;i++) cin >> arr[i];
    cout << recursion(0, N - 1);
    return 0;
}
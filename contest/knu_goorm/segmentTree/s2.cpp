#include <stdio.h>
#include <iostream>

using namespace std;

int arr[1000005], n, m;
long long rangeSum[4000020];

long long init(int l, int r, int node){
    if(l==r)
        return rangeSum[node] = arr[l];
    
    int mid = (l + r) / 2;
    return rangeSum[node] = init(l,mid, node*2) + init(mid+1,r, node*2+1);
}

long long update(int index, int value, int node, int l, int r){
    if(index < l || r < index)
        return rangeSum[node];
    if(l==r)
        return rangeSum[node]=arr[index]=value;
    int mid = (l + r) /2;
    return rangeSum[node] = update(index, value, node*2, l, mid) + update(index, value, node*2+1, mid+1,r);
}

long long query(int l, int r, int node, int nl, int nr){
    if(nr<l || r <nl)
        return 0;
    if(l<=nl && nr<=r)
        return rangeSum[node];
    int mid = (nl + nr) / 2;
    return query(l, r, node*2, nl, mid) + query(l,r,node*2,mid+1, nr);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "rt", stdin);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    init(1, n, 1);
    int a, b, c;
    for(int i=0;i<m*2;i++){
        cin >> a >> b >> c;
        if(a==1)
            update(b,c,1,1,n);
        if(a==2)
            cout << query(b,c,1,1,n) << '\n';
    }
}
#include <iostream>

using namespace std;

int a[100], temp[100];

void merge(int lt, int rt){
    int mid = (lt+rt)/2;
    int p1=lt, p2=mid+1, p3=lt;
    while(p1<=mid && p2<=rt){
        if(a[p1]<a[p2]) temp[p3++] = a[p1++];
        else temp[p3++] = a[p2++];
    }

    while(p1<=mid) temp[p3++] = a[p1++];
    while(p2<=rt) temp[p3++] = a[p2++];

    for(int i=lt;i<=rt;i++) a[i]=temp[i];
}
void divide(int lt, int rt){
    int mid = (lt+rt)/2;
    if(lt<rt){
        divide(lt, mid);
        divide(mid+1, rt);
        merge(lt, rt);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt","rt",stdin);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)   cin >> a[i];
    divide(1,10);
    for(int i=1;i<=n;i++)   cout << a[i] << " ";
    return 0;
}
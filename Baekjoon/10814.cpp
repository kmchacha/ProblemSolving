#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int age[100001], temp_age[100001];
char* name[100001], str[100001][101];

void merge(int lt, int rt){
    int mid = (lt+rt)/2;
    int p1=lt, p2=mid+1, p3=lt;
    char* temp_name[100001];
    while(p1<=mid && p2<=rt){
        if(age[p1] <= age[p2]) { temp_age[p3] = age[p1]; temp_name[p3++] = name[p1++]; }
        else { temp_age[p3] = age[p2]; temp_name[p3++] = name[p2++]; }
    }

    while(p1<=mid) {temp_age[p3]=age[p1]; temp_name[p3++]=name[p1++];}
    while(p2<=rt) {temp_age[p3]=age[p2]; temp_name[p3++]=name[p2++];}

    for(int i=lt;i<=rt;i++){
        age[i] = temp_age[i];
        name[i] = temp_name[i];
    }
}
void divide(int lt, int rt){
    if(lt<rt){
        int mid = (lt+rt)/2;
        divide(lt, mid);
        divide(mid+1, rt);
        merge(lt, rt);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    int n;
    cin >> n;
    
    for(int i=1;i<=n;i++) {
        int a; 
        cin >> a >> str[i];
        age[i] = a;
        name[i] = str[i];
    }

    divide(1, n);
    for(int i=1;i<=n;i++) {
        cout << age[i] << " " << name[i] <<'\n';
    }
    return 0;
}
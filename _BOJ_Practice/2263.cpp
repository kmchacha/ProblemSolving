#include <bits/stdc++.h>

using namespace std;

int inorder[100005], postorder[100005], N, idx[100005];
void preorder(int inStart, int inEnd, int postStart, int postEnd){
    if(inStart > inEnd || postStart > postEnd) return;

    int root = postorder[postEnd];
    cout << root << " ";
    preorder(inStart, idx[root] - 1, postStart, postStart + idx[root] - inStart -1);
    preorder(idx[root] + 1, inEnd, postStart + idx[root] - inStart, postEnd - 1);
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    cin >> N;
    for(int i=0;i<N;i++) cin >> inorder[i];
    for(int i=0;i<N;i++) cin >> postorder[i];
    for(int i=0;i<N;i++) idx[inorder[i]] = i;
    preorder(0, N-1, 0, N-1);
    return 0;   
}
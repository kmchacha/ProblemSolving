#include <iostream>
#include <functional>
#include <queue>

using namespace std;

// priority_queue 는 기본적으로 MAX_Heap이다
// priority_queue< int, vector<int>, less<int> > pq;    // MAX HEAP
// priority_queue< int, vector<int>, greater<int> > pq; // MIN HEAP
int main(){

	// priority_queue
	//priority_queue< int, vector<int>, less<int> > pq;
    priority_queue<int> pq;
    //priority_queue<int, vector<int>, greater<int> > pq;

	// push(element)
	pq.push(5);
	pq.push(2);
	pq.push(8);
	pq.push(9);
	pq.push(1);
	pq.push(14);


	// pop()
	pq.pop();
	pq.pop();


	// top();
	cout << "pq top: " << pq.top() << '\n';


	// empty(), size()
	if(!pq.empty()) cout << "pq size: " << pq.size() << '\n';


	// pop all
	while(!pq.empty()){
		cout << pq.top() << " ";
		pq.pop();
	}

	cout << '\n';

	return 0;

}
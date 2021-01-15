// C++ program to find med in 
// stream of running integers 
#include<bits/stdc++.h> 
using namespace std; 

// function to calculate med of stream 
void printMedians(int arr[], int n) 
{ 
	// max heap to store the smaller half elements 
	priority_queue<int> s; 

	// min heap to store the greater half elements 
	priority_queue<int,vector<int>,greater<int> > g; 

	int med = arr[0]; 
	s.push(arr[0]); 

	cout << med << endl; 

	// reading elements of stream one by one 
	/* At any time we try to make heaps balanced and 
		their sizes differ by at-most 1. If heaps are 
		balanced,then we declare median as average of 
		min_heap_right.top() and max_heap_left.top() 
		If heaps are unbalanced,then median is defined 
		as the top element of heap of larger size */
	for (int i=1; i < n; i++) 
	{ 
		int x = arr[i]; 

		// case1(left side heap has more elements) 
		if (s.size() > g.size()) 
		{ 
			if (x < med) 
			{ 
				g.push(s.top()); 
				s.pop(); 
				s.push(x); 
			} 
			else
				g.push(x); 

			med = (s.top() + g.top())/2.0; 
		} 

		// case2(both heaps are balanced) 
		else if (s.size()==g.size()) 
		{ 
			if (x < med) 
			{ 
				s.push(x); 
				med = (int)s.top(); 
			} 
			else
			{ 
				g.push(x); 
				med = (int)g.top(); 
			} 
		} 

		// case3(right side heap has more elements) 
		else
		{ 
			if (x > med) 
			{ 
				s.push(g.top()); 
				g.pop(); 
				g.push(x); 
			} 
			else
				s.push(x); 

			med = (s.top() + g.top())/2.0; 
		} 

		cout << med << endl; 
	} 
} 

// Driver program to test above functions 
int main() 
{ 
	// stream of integers 
	int arr[] = {5, 15, 10, 20, 3}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	printMedians(arr, n); 
	return 0; 
} 


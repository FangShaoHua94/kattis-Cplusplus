#include <iostream>

using namespace std;

class ListArray { 
	private: 
		int N; 
		int A[10]; // question 1a 
		//no initiation?
		//limit the number of element to 10
	public: 
		ListArray() : N(0) {} // question 1b 
		//constructor no parameter,assign n=0, n is the number of element
		int get(int i) {
			if((i < 0) || (i > N)){
				return -999;
			}
			return A[i]; // question 1c 
			//index not assign with value yet,give default or random value
			//should check i is within the index bound
		}
		int search(int v) { 
			for (int i = 0; i < N; ++i) 
				if (A[i] == v) 
					return i; 
			return -1; 
		} 
		void insert(int i, int v) { 
			if ((N == 10) || (i < 0) || (i > N)) return; // question 1d 
			//array full  at 10 elements or index out of bound
			for (int j = N; j > i; --j){ // question 1e
			//should do from back to from, doing from to back will lose previous elements
				A[j] = A[j-1]; 
			}
			A[i] = v; 
			++N; 
		} 
		void remove(int i) { 
			for (int j = i; j < N-1; ++j) // question 1f 
			//check if the given parameter i is wihtin the bound of the index
				A[j] = A[j+1]; 
			--N; 
		} 
		void printList() { 
			for (int i = 0; i < N; ++i) { 
				if (i) cout << " "; 
				cout << A[i]; 
			} 
			cout << endl; 
		}
		void sortList() { // sort array A, question 1g
		    for(int i=1;i<N;i++){
		        for(int j=i;j>0&&A[j-1]>A[j];j--){
		            swap(A[j-1],A[j]);
		        }
		    }
		    //or sort using library sort
		}	
};

int main() { 
	ListArray* LA = new ListArray(); // question 1h 
	ListArray LA2; //yes
	//later use LA2.insert() instead of using the arrow
	//since the ListArray* uses the address/pointer
	//whereas the ListArray uses the variable
	//object is pass by value
	LA->insert(0, 5); 
	LA->insert(0, 1);
	LA->insert(0, 4);
	LA->insert(0, 7);
	LA->insert(0, 2); // we should have A = {2, 7, 4, 1, 5} by now 
	LA->printList();
	cout << LA->get(3) << endl; // 1, A[3] = 1 
	cout << LA->search(4) << endl; // 2, A[2] = 4 
	cout << LA->search(6) << endl; // not found, -1 
	LA->printList(); 
	LA->remove(1); // we should have A = {2, 4, 1, 5} by now 
	LA->printList(); 
	cout << LA->search(4) << endl; // 1, A[1] = 4 now 
	cout << LA->search(7) << endl; // not found, -1 
	LA->printList(); // unsorted 
	LA->sortList(); // we should have A = {1, 2, 4, 5} by now 
	LA->printList(); // sorted 
	return 0; 
}

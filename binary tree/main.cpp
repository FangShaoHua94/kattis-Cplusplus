#include <bits/stdc++.h>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct node{
	int val;
	node *left;
	node *right;
	node *parent;
	node(int value){
		this->val=value;
		right=NULL;
		left=NULL;
	}
};

class BTMax{
	private:
		node *root;
		int num;
	public:
		BT(){
			num=0;
			root=NULL;
		}
		
		bool isleaf(node x){
			return x.right==NULL||x.left==NULL;
		}
		
		
		void insert(int x){
			node *y=new node(x);
			num++;
			if(root==NULL){
				root=y;
				return;
			}
			node *temp=root;
			while(!isleaf(temp)){
				
			}
			
			
		}
	
		void shiftup(){
			
		}
};

int main() {
	return 0;
}

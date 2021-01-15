#include <bits/stdc++.h>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct node{
	int val;
	node *pre;
	node *next;
	node(int value){
		this->val=value;
		pre=NULL;
		next=NULL;
	}
};

class CDLL{
	private:
		node *head,*tail;
		int num;
	public:
		CDLL(){
			num=0;
			head=NULL;
			tail=NULL;
		}
		
		bool empty(){
			return num==0;
		}
		
		int size(){
			return num;
		}
		
		bool present(int x){
			if(head==NULL){
				return false;
			}
			node *temp=head;
			for(int i=0;i<num;i++){
				if(temp->val==x){
					return true;
				}
				temp=temp->next;
			}
			return false;
		}
		
		int getindex(int x){
			if(head==NULL){
				return -999;
			}
			node *temp=head;
			for(int i=0;i<num;i++){
				if(temp->val==x){
					return i;
				}
				temp=temp->next;
			}
			return -999;
		}
		
		int getval(int index){
			if(index<0||index>num){
				return -999;
			}
			node *temp=head;
			for(int i=0;i<index;i++){
				temp=temp->next;
			}
			return temp->val;
		}
		
		void inserthead(int x){
			node *y=new node(x);
			num++;
			if(head==NULL){
				head=y;
				tail=y;
				y->next=y;
				y->pre=y;
				return;
			}
			y->next=head;
			y->pre=tail;
			head->pre=y;
			tail->next=y;
			head=y;
		}
		
		void inserttail(int x){
			node *y=new node(x);
			num++;
			if(head==NULL){
				head=y;
				tail=y;
				y->pre=y;
				y->next=y;
				return;
			}
			y->pre=tail;
			y->next=head;
			tail->next=y;
			head->pre=y;
			tail=y;
		}
		
		void insertat(int index,int value){
			if(index==0){
				inserthead(value);
				return;
			}
			if(index==num){
				inserttail(value);
				return;
			}
			num++;
			index=index%num;
			node *y=new node(value);
			node *temp=head;
			for(int i=0;i<index;i++){
				temp=temp->next;
			}
			temp->pre->next=y;
			y->pre=temp->pre;
			y->next=temp;
			temp->pre=y;
		}
		
		void deletehead(){
			if(head!=NULL){
				head->next->pre=tail;
				tail->next=head->next;
				head=head->next;
				num--;
				if(num==0){
					head=NULL;
					tail=NULL;
				}
			}
		}
		
		void deletetail(){
			if(head!=NULL){
				tail->pre->next=head;
				head->pre=tail->pre;
				tail=tail->pre;
				num--;
				if(num==0){
					head=NULL;
					tail=NULL;
				}
			}
		}
	
		void print(){
			node *temp=head;
			for(int i=0;i<num;i++){
				cout<<temp->val<<" ";
				temp=temp->next;
			}
			cout<<endl;
		}
		
		void reverseprint(){
			node *temp=tail;
			for(int i=0;i<num;i++){
				cout<<temp->val<<" ";
				temp=temp->pre;
			}
			cout<<endl;
		}
};


int main() {
	CDLL cdll;
	cdll.inserthead(4);
	cdll.inserthead(7);
	cdll.inserttail(6);
	cdll.inserttail(1);
	cdll.print();
	cdll.insertat(10,100);
	cdll.print();
	return 0;
}

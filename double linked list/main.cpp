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


class DLL{
	private:
		node *head,*tail;
		int num;
		
	public:
		DLL(){
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
			while(temp!=NULL){
				if(temp->val==x){
					return true;
				}
				temp=temp->next;
			}
			return false;
		}
		
		void addtohead(int x){
			node *y=new node(x);
			num++;
			if(head==NULL){
				head=y;
				tail=y;
				return;
			}
			y->next=head;
			head->pre=y;
			head=y;
		}
		
		void addtotail(int x){
			node *y=new node(x);
			num++;
			if(head==NULL){
				head=y;
				tail=y;
				return;
			}
			tail->next=y;
			y->pre=tail;
			tail=y;
		}
		
		void insert(int x, int index){
			if(index<0||index>num){
				return;
			}
			if(index==0){
				addtohead(x);
				return;
			}
			if(index==num){
				addtotail(x);
				return;
			}
			node *y=new node(x);
			int count=0;
			node *temp=head;
			while(count+1!=index){
				temp=temp->next;
				count++;
			}
			y->next=temp->next;
			temp->next->pre=y;
			y->pre=temp;
			temp->next=y;
			num++;
		}
		
		void removehead(){
			if(num>0){
				node *d=head;
				if(head==tail){
					head=NULL;
					tail=NULL;
				}else{
					head->next->pre=NULL;
					head=head->next;
				}
				delete d;
				num--;
			}
		}
		
		void removetail(){
			if(num>0){
				if(head==tail){
					removehead();
				}else{
					node *d=tail;
					tail->pre->next=NULL;
					tail=tail->pre;
					delete d;
					num--;
				}
			}
		}
		
		void deleteindex(int index){
			if(index<0||index>num){
				return;
			}
			if(index==0){
				removehead();
				return;
			}
			if(index==num){
				removetail();
				return;
			}
			node *temp;
			if(index>(num+1)/2){
				int count=num-index;
				temp=tail;
				for(int i=0;i<count;i++){
					temp=temp->pre;
				}
			}else{
				int count=index;
				temp=head;
				for(int i=0;i<count;i++){
					temp=temp->next;
				}
			}
			temp->pre->next=temp->next;
			temp->next->pre=temp->pre;
			delete temp;
			num--;
		}
		
		void printlist(){
			node *temp=head;
			while(temp!=NULL){
				cout<<temp->val<<" ";
				temp=temp->next;
			}cout<<endl;
		}
	
	
	
};


int main() {
	
	DLL dll;
	cout<<dll.empty()<<endl;
	
	dll.addtohead(1);
	cout<<dll.empty()<<endl;
	dll.addtotail(9);
	dll.addtotail(9);
	cout<<dll.present(1)<<endl;
	cout<<dll.present(2)<<endl;
	dll.addtotail(9);
	dll.insert(100,0);
	dll.printlist();
	dll.deleteindex(1);
	dll.printlist();
	return 0;
}

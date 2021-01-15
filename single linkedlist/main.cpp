#include <bits/stdc++.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct node{
	int value;
	node *next;
	node(int val){
		this->value=val;
		next=NULL;
	}
};

class SLL{
	private:
		node *head,*tail;
		int num;
	
	public:
		
		SLL(){
			head=NULL;
			tail=NULL;
			num=0;
		}
		
		bool empty(){
			return num==0;
		}
		
		int size(){
			return num;
		}
		
		int getval(int index){
			if(head==NULL||index>num||index<0){
				return -999;
			}
			node *temp=head;
			for(int i=0;i<index;i++){
				temp=temp->next;
			}
			return temp->value;
		}
		
		node* getnode(int index){
			if(head==NULL||index>num||index<0){
				return NULL;
			}
			node *temp=head;
			for(int i=0;i<index;i++){
				temp=temp->next;
			}
			return temp;
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
			temp->next=y;
			num++;
		}
		
		bool present(int x){
			if(head==NULL){
				return false;
			}
			node *temp=head;
			while(temp!=NULL){
				if(temp->value==x){
					return true;
				}
				temp=temp->next;
			}
			return false;
		}
		
		int getindex(int x){
			node *temp=head;
			int index=0;
			while(temp!=NULL){
				if(temp->value==x){
					break;
				}
				temp=temp->next;
				index++;
			}
			if(temp==NULL){
				return -999;
			}
			return index;
		}
		
		int get_nthindex(int x,int n){
			if(n<=0||n>num){
				return -999;
			}
			node *temp=head;
			int index=0,count=0;
			while(temp!=NULL){
				if(temp->value==x){
					count++;
					if(count==n){
						break;
					}
				}
				temp=temp->next;
				index++;
			}
			if(temp==NULL){
				return -999;
			}
			return index;
		}
		
		void removehead(){
			if(num>0){
				node *d=head;
				if(head==tail){
					head=NULL;
					tail=NULL;
				}else{
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
					node *temp=head;
					while(temp->next!=tail){
						temp=temp->next;
					}
					temp->next=NULL;
					tail=temp;
					delete d;
					num--;
				}
			}
		}
		
		void removefirst(int x){
			node *temp=head;
			node *pre;
			while(temp!=NULL){
				if(temp->value==x){
					if(temp==head){
						removehead();
					}else if(temp==tail){
						removetail();
					}else{
						pre->next=temp->next;
						delete temp;
						num--;
					}
					return;
				}
				pre=temp;
				temp=temp->next;
			}
		}
		
		void remove_nth(int x,int n){
			if(n<=0||n>num){
				return;
			}
			int count=0;
			node *temp=head;
			node *pre;
			while(temp!=NULL){
				if(temp->value==x){
					count++;
					if(count==n){
						if(temp==head){
							removehead();
						}else if(temp==tail){
							removetail();
						}else{
							pre->next=temp->next;
							delete temp;
							num--;
						}
						return;
					}
				}
				pre=temp;
				temp=temp->next;
			}
		}
		
		void removelast(int x){
			node *temp=head;
			node *pre;
			node *temp2=NULL;
			node *pre2=NULL;
			while(temp!=NULL){
				if(temp->value==x){
					temp2=temp;
					pre2=pre;
				}
				pre=temp;
				temp=temp->next;
			}
			if(pre2!=NULL){
				if(temp==head){
					removehead();
				}else if(temp==tail){
					removetail();
				}else{
					pre2->next=temp2->next;
					delete temp2;
					num--;
				}
			}
		}
		
		void printlist(){
			node *temp=head;
			while(temp!=NULL){
				cout<<temp->value<<" ";
				temp=temp->next;
			}cout<<endl;
		}
	
	
};

int main() {
	SLL sll;
	cout<<sll.empty()<<endl;
	sll.addtohead(1);
	sll.addtohead(2);
	sll.addtohead(1);
	sll.addtohead(2);
	sll.addtohead(1);
	sll.addtohead(2);
	sll.addtohead(1);
	sll.addtohead(2);
	sll.addtohead(1);
	sll.addtohead(2);
	sll.addtohead(1);
	sll.printlist();
	sll.removefirst(1);
	sll.printlist();
	sll.remove_nth(1,3);
	sll.printlist();
	sll.removelast(2);
	sll.printlist();
//	sll.addtotail(6);
//	sll.addtotail(8);
//	sll.printlist();
//	cout<<sll.empty()<<endl;
//	cout<<sll.getindex(6)<<endl;
//	cout<<sll.present(1)<<endl;
//	cout<<sll.getval(1)<<endl;
//	sll.removefirst(2);
//	sll.removehead();
//	sll.removetail();
	
	
	
	
	
	return 0;
}

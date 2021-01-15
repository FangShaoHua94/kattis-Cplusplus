#include <bits/stdc++.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


class SLL{
	struct Vertex{
		int item;
		Vertex *next;
	};
	private:
		Vertex *head,*tail;
	public:
		SLL(){
			head=tail=NULL;
		}
		void InsertAtHead(int value){
			Vertex *vtx=new Vertex();
			vtx->item=value;
			vtx->next=head;
			if(head==NULL){
				tail=vtx;
			}
			head=vtx;
		}
		void InsertAfterTail(int value){
			if(head==NULL){
				InsertAtHead(value);
			}else{
				Vertex *vtx=new Vertex();
				vtx->item=value;
				tail->next=vtx;
				tail=vtx;
			}
		}
		void printlist(){
			for(Vertex *vtx=head;vtx!=NULL;vtx=vtx->next){
				cout<<vtx->item<<" ";
			}cout<<endl;
		}
		
		SLL partition(){
			SLL temp;
			Vertex *p=head;
			temp.InsertAtHead(p->item);
			for(Vertex *v=head->next;v!=NULL;v=v->next){
				if(v->item>head->item){
					temp.InsertAfterTail(v->item);
				}else{
					temp.InsertAtHead(v->item);
				}
			}
			return temp;
		}
};


int main() {
	SLL L,Lmod;
	L.InsertAfterTail(5);L.InsertAfterTail(8);L.InsertAfterTail(6);
	L.InsertAfterTail(1);L.InsertAfterTail(7);L.InsertAfterTail(2);
	Lmod=L.partition();
	L.printlist();
	Lmod.printlist();
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct cat{
	int arrindex;
	string name;
	int severity;
	int pos;
};

class heap{
	private:
		int num;
		cat *v[200010];
		
		bool compare(cat *p,cat *c){
			if(p->severity!=c->severity){
				return p->severity<c->severity;
			}
			return p->arrindex>c->arrindex;
		}
		
//		void swap(cat *p,cat *c){
//			cat temp=*p;
//			*p=*c;
//			*c=temp;
//			
//			int newpos=p->pos;
//			p->pos=c->pos;
//			c->pos=newpos;
//			
//			cout << "swap " << p->name << " " << c->name << endl;
//			cout << "position " << p->pos << " " << c->pos << endl;
//		}
		
		void heapify(int i){
			int l=left(i),r=right(i),largest=i;
			if(l<num&&compare(v[i],v[l])){
				largest=l;
			}
			if(r<num&&compare(v[largest],v[r])){
				largest=r;
			}
			if(largest!=i){
				swap(v[i],v[largest]);
				swap(v[i]->pos, v[largest]->pos);
				heapify(largest);
			}
		}
		
		int parent(int i){
			return (i-1)/2;
		}
		int left(int i){
			return 2*i+1;
		}
		int right(int i){
			return 2*i+2;
		}
		
	public:
		heap(){
			num=0;
		}
		
		void insert(cat *x){
			num++;
			int i=num-1;
			x->pos=i;
			v[i]=x;
			while(i!=0&&compare(v[parent(i)],v[i])){
				swap(v[i],v[parent(i)]);
				swap(v[i]->pos, v[parent(i)]->pos);
				i=parent(i);
			}
		}
		
		string top(){
			if(num==0){
				return "The clinic is empty";
			}
			return v[0]->name;
		}
		
		void erase(int i){
			if(num==0){
				return;
			}
			if(num==1){
				num--;
				return;
			}
			bool flag=compare(v[i],v[num-1]);
			v[i]=v[num-1];
			v[i]->pos=i;
			num--;
			if(flag){
				while(i!=0&&compare(v[parent(i)],v[i])){
					swap(v[i],v[parent(i)]);
					swap(v[i]->pos, v[parent(i)]->pos);
					i=parent(i);
				}
			}else{
				heapify(i);
			}
		}
		
		void update(int i,int value){
			v[i]->severity+=value;
			while(i!=0&&compare(v[parent(i)],v[i])){
				swap(v[i],v[parent(i)]);
				swap(v[i]->pos, v[parent(i)]->pos);
				i=parent(i);
			}
		}
		
		void print(){
			cout<<"current heap:"<<endl;
			int i=0;
			while(i<num){
				cout<<"["<<v[i]->name<<" "<<v[i]->severity<<" "<<v[i]->pos<<"] ";
				i++;
				if(ceil(log2(i+1))==floor(log2(i+1))){
					cout<<endl;
				}
			}
			cout<<endl;
		}
};


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int N,arrindex=0;
	cin>>N;
	
	unordered_map<string,cat*> m;
	heap h;
	int command,severity,increase;
	string name;
	
	while(N--){
//		cout<<"N"<<N<<endl;
		cin>>command;
		if(command==0){
			//insert
			cin>>name>>severity;
			cat *x=new cat();
			x->arrindex=arrindex;
			x->name=name;
			x->severity=severity;
			x->pos=-1;
			m[name] = x;
			h.insert(x);
		}else if(command==1){
			//update
			cin>>name>>increase;
			cat *x=m[name];
			h.update(x->pos,increase);
		}else if(command==2){
			//erase this cat
			cin>>name;
			cat *x=m[name];
			h.erase(x->pos);
		}else{
			//print max
			cout<<h.top()<<endl;
		}
//		h.print();
	}
	
	return 0;
}
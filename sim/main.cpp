#include <bits/stdc++.h>

using namespace std;

//string generatestr(){
//	
//	int n=1000;
//	string str(n,'1');
//	cout<<n<<endl;
//	cout<<"str:";
//	for(int i=0;i<n;i++){
//		char ch=(char)((rand()%(126-32))+32);
//		cout<<ch;
//		str.at(i)=ch;
//	}
//	cout<<endl;
//	cout<<"str:"<<str<<endl;
//	return str;
//}

struct node{
	char val;
	node* pre;
	node* next;
	
	node(char val){
		this->val=val;
		next=NULL;
		pre=NULL;
	}
};

class Mylist{
	private:
		node *prehead,*tail,*curr;
		int num;
	public:
		Mylist(){
			node *x=new node('q');
			prehead=x;
			curr=prehead;
			tail=prehead;
			num=0;
		}
		void gotohome(){
			curr=prehead;
		}
		void gotoend(){
			curr=tail;
		}
		void addtocurr(char x){
			node *y=new node(x);
			if(num==0){
                curr->next=y;
                tail=y;
                y->pre=prehead;
                curr=y;
			}else{
                y->next=curr->next;
                if(curr!=tail){
                    curr->next->pre=y;
                }else{
                	tail=y;
				}
                y->pre=curr;
                curr->next=y;
                curr=y;
			}
			num++;
		}
		void backspace(){
            if(curr!=prehead){
                node *temp;
                temp=curr;
                curr->pre->next=curr->next;
                if(curr!=tail){
                    curr->next->pre=curr->pre;
                }else{
                    tail=curr->pre;
                }
                curr=curr->pre;
                delete temp;
                num--;
            }
		}
		void print(){
            node *temp = prehead->next;
			while(temp!=NULL) {
		        cout<<temp->val;
//		        node *ti=temp;
		        temp = temp->next;
//		        delete ti;
		    }
		    cout<<endl;
		}
};

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);

	int tc;
	scanf("%d ",&tc);
	char str[1000000];
	while(tc--){
		scanf("%100[ -~]",str);
//		str=generatestr();
//		cout<<"done generation! "<<str<<endl;
		Mylist mlist;
		int i=0;
		char ch=str[i++];
		while(ch!='\0'){
//			cout<<ch<<": "<<endl;
			switch(ch){
				case '<':
//				    cout<<"backspace "<<endl;
                    mlist.backspace();
                    break;
                case '[':
//                    cout<<"gotohome "<<endl;
                    mlist.gotohome();
                    break;
                case ']':
//                    cout<<"gotoend "<<endl;
                    mlist.gotoend();
                    break;
                default:
//                    cout<<"addtocurr ";
                    mlist.addtocurr(ch);
//                    mlist.print();
			}
			ch=str[i++];
		}
		mlist.print();

//		delete &mlist;
	}
	return 0;
}



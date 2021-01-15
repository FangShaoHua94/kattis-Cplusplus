#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef tree<string, null_type, less<string>, rb_tree_tag, 
             tree_order_statistics_node_update> 
    tree_set; 


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
	tree_set boy[26];
    tree_set girl[26];	
    map<string,int> m;
    
    int command;
    cin>>command;

    while(command){
        string name,start,end;
        int gen,count=0,startc,endc,r1,r2;

        switch(command){
            case 1:
                cin>>name>>gen;
                m[name]=gen;
                if(gen==1){
                    boy[(int)(name[0]-'A')].insert(name);
                }else{
                	girl[(int)(name[0]-'A')].insert(name);
                }
                break;
            case 2:
                cin>>name;
                if(m[name]==1){
                	boy[(int)(name[0]-'A')].erase(name);
                }else{
                	girl[(int)(name[0]-'A')].erase(name);
                }
                break;
            case 3:
                cin>>start>>end>>gen;
             	startc=(int)(start[0]-'A');
             	endc=(int)(end[0]-'A');
                if(gen==1){
                	if(startc==endc){
                		r1=boy[startc].order_of_key(start);
	                	r2=boy[startc].order_of_key(end);
	//                	cout<<"["<<r1<<" "<<r2<<endl;
						if(r1<=r2){
							count+=r2-r1;
						}
					}else{
						for(int i=startc;i<=endc;i++){
                			if(i==startc){
                				count+=boy[i].size()-boy[i].order_of_key(start);
							}else if(i==endc){
								count+=boy[i].order_of_key(end);
							}else{
								count+=boy[i].size();
							}
						}
					}
					
                }else if(gen==2){
                	if(startc==endc){
                		r1=girl[startc].order_of_key(start);
	                	r2=girl[startc].order_of_key(end);
	//                	cout<<"["<<r1<<" "<<r2<<endl;
						if(r1<=r2){
							count+=r2-r1;
						}
					}else{
						for(int i=startc;i<=endc;i++){
                			if(i==startc){
                				count+=girl[i].size()-girl[i].order_of_key(start);
							}else if(i==endc){
								count+=girl[i].order_of_key(end);
							}else{
								count+=girl[i].size();
							}
						}
					}
                }else{
                	if(startc==endc){
                		r1=boy[startc].order_of_key(start);
	                	r2=boy[startc].order_of_key(end);
	//                	cout<<"["<<r1<<" "<<r2<<endl;
						if(r1<=r2){
							count+=r2-r1;
						}
					}else{
						for(int i=startc;i<=endc;i++){
                			if(i==startc){
                				count+=boy[i].size()-boy[i].order_of_key(start);
							}else if(i==endc){
								count+=boy[i].order_of_key(end);
							}else{
								count+=boy[i].size();
							}
						}
					}
					if(startc==endc){
                		r1=girl[startc].order_of_key(start);
	                	r2=girl[startc].order_of_key(end);
	//                	cout<<"["<<r1<<" "<<r2<<endl;
						if(r1<=r2){
							count+=r2-r1;
						}
					}else{
						for(int i=startc;i<=endc;i++){
                			if(i==startc){
                				count+=girl[i].size()-girl[i].order_of_key(start);
							}else if(i==endc){
								count+=girl[i].order_of_key(end);
							}else{
								count+=girl[i].size();
							}
						}
					}
					
                }
                cout<<count<<"\n";
        }
        cin>>command;
    }
    return 0;
}



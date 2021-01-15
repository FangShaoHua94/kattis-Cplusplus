#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

int n, m;

int spot(int i, int j) {
    return i*n+j;
}

int find(vector<int>& d, int a) {
    if(d[a] == -1) {
        return a;
    }
    return d[a] = find(d, d[a]);
}

void join(vector<int>& d, int a, int b) {
    a = find(d, a);
    b = find(d, b);
    if(a == b) return;
    d[a] = b;
}


int main(int argc, char** argv) {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int r,c;
	cin>>c>>r;
	while(r!=0&&c!=0){
	
	n=c;
	m=r;
	int mapz[r][c];
	int hashh[r][c];
	vector<bool> valid(r*c,true);
	vector<int> vv(r*c,1);
	
//	for(int i=0;i<r;i++){
//		for(int j=0;j<c;j++){
//			cin>>mapz[i][j];
//			hashh[i][j]=i*c+j;
//		}
//	}
	

	
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			mapz[i][j]=rand()%10;
			cout<<mapz[i][j]<<" ";
			hashh[i][j]=i*c+j;
		}
		cout<<endl;
	}
	
	
		
	cout<<endl;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cout<<hashh[i][j]<<" ";
		}
		cout<<endl;
	}cout<<endl;
	
	
//	cout<<endl;
//	for(int i=0;i<r;i++){
//		for(int j=0;j<c;j++){
//			cout<<hashh[i][j]<<" ";
//		}
//		cout<<endl;
//	}cout<<endl;
	
	
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cout<<"["<<i<<","<<j<<"]"<<endl;
			if(i+1<r){
				if(mapz[i+1][j]>mapz[i][j]){
					valid[hashh[i+1][j]]=false;
				}else if(mapz[i+1][j]<mapz[i][j]){
					valid[hashh[i][j]]=false;
				}else{
					//if havent hassh,then hassh it
					//if hasshed, then is this one hashed
					//if yes then dont do anyhting
					//else i hashh to him
					
					if(hashh[i+1][j]==(i+1)*c+j){
						vv[hashh[i+1][j]]=0;
						hashh[i+1][j]=hashh[i][j];
						vv[hashh[i][j]]++;
					}else{
						if(hashh[i][j]==i*c+j){
							vv[hashh[i][j]]=0;
							hashh[i][j]=hashh[i+1][j];
							vv[hashh[i][j]]++;
						}
					}
				}
			}
//			for(int ii=0;ii<r*c;ii++){
//				cout<<"["<<valid[ii]<<","<<vv[ii]<<"]";
//				if((ii+1)%c==0){
//					cout<<endl;
//				}
//			}cout<<endl;

			if(j+1<c){
				if(mapz[i][j+1]>mapz[i][j]){
					valid[hashh[i][j+1]]=false;
				}else if(mapz[i][j+1]<mapz[i][j]){
					valid[hashh[i][j]]=false;
				}else{
					if(hashh[i][j+1]==i*c+j+1){
						vv[hashh[i][j+1]]=0;
						hashh[i][j+1]=hashh[i][j];
						vv[hashh[i][j]]++;
					}else{
						if(hashh[i][j]==i*c+j){
							vv[hashh[i][j]]=0;
							hashh[i][j]=hashh[i][j+1];
							vv[hashh[i][j]]++;
						}
					}
				}
			}
			
//			for(int ii=0;ii<r*c;ii++){
//				cout<<"["<<valid[ii]<<","<<vv[ii]<<"]";
//				if((ii+1)%c==0){
//					cout<<endl;
//				}
//			}cout<<endl;
		
		}
	}
	
	cout<<endl;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cout<<hashh[i][j]<<" ";
		}
		cout<<endl;
	}cout<<endl;
	
//	for(int i=0;i<r;i++){
//		for(int j=0;j<c;j++){
//			cout<<hashh[i][j]<<" ";
//		}
//		cout<<endl;
//	}cout<<endl;
//	
//	for(int i=0;i<r;i++){
//		for(int j=0;j<c;j++){
//			cout<<hashh[i][j]<<" ";
//		}
//	}
	cout<<endl;
	for(int i=0;i<r*c;i++){
		cout<<"["<<valid[i]<<","<<vv[i]<<"]";
		if((i+1)%c==0){
			cout<<endl;
		}
	}cout<<endl;
	
	
	int ccc=0;
	for(int i=0;i<r*c;i++){
		if(valid[i]==1){
			ccc+=vv[i];
		}
	}
	cout<<ccc<<endl;
	
	
	vector<vector<int>> v;
    v.resize(m, vector<int>(n));

    for(int i=0;i<r;i++){
    	for(int j=0;j<c;j++){
    		v[i][j]=mapz[i][j];
		}
	}

    vector<bool> works(n*m, true);
    vector<int> d(n*m, -1);

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(i > 0) {
                if(v[i][j] == v[i-1][j]) {
                    join(d, spot(i,j), spot(i-1,j));
                }
                else if(v[i][j] < v[i-1][j]) {
                    works[spot(i-1,j)] = false;
                }
                else {
                    works[spot(i,j)] = false;
                }
            }
            if(j > 0) {
                if(v[i][j] == v[i][j-1]) {
                    join(d, spot(i,j), spot(i,j-1));
                }
                else if(v[i][j] < v[i][j-1]) {
                    works[spot(i,j-1)] = false;
                }
                else {
                    works[spot(i,j)] = false;
                }
            }
        }
    }

    for(int i = 0; i < n*m; i++) {
        int here = find(d, i);
        if(!works[i]) {
            works[here] = false;
        }
    }

    int count = 0;
    for(int i = 0; i < n*m; i++) {
        int here = find(d, i);
        if(works[here]) {
            count++;
        }
    }
    
    cout << count << endl;
    
    cin>>c>>r;
}
    
	
	return 0;
}

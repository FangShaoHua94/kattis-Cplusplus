#include <bits/stdc++.h>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class module{
	private:
		string code,name;
		int max_quota;
		vector<string> roster;
	
	public:
		module(string _code,string _name,int _max_quota):code(_code){
			name=_name;
			max_quota=_max_quota;
		}
		
		string getDisplayName(){
			return code+" - "+name;
		}
		
		int inClassRoster(string studentName){
			for(int i=0;i<roster.size();i++){
				if(roster[i]==studentName){
					return i;
				}
			}
			return -1;
		}
		
		void addStudent(string studentName){
			if(roster.size()==max_quota||inClassRoster(studentName)!=-1){
				return;
			}
			if(roster.size()==0){
				roster.push_back(studentName);
				return;
			}
			int i;
			for(i=0;i<roster.size();i++){
				if(roster[i].compare(studentName)>0){
					break;
				}
			}
			roster.insert(roster.begin()+i,studentName);
		}
		
		void dropStudent(string studentName){
			for(int i=0;i<roster.size();i++){
				if(roster[i]==studentName){
					roster.erase(roster.begin()+i);
					return;
				}
			}
		}
		
		void printClassRoster(){
			for(auto &s:roster){
				cout<<s<<endl;
			}cout<<"--------\n";
		}
};

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	module m("CS2040C","Data Structures and Algorithms",8);
	cout<<m.getDisplayName()<<endl;
	m.addStudent("Ammar Fathin Sabili");
	m.addStudent("Ghozali Suhariyanyo Hadi");
	m.addStudent("Sidhant Bansal");
	m.addStudent("Teh NianFei");
	m.addStudent("Mohideen Imran Khan");
	m.addStudent("Mohideen Imran Khan");
	m.addStudent("Ler Wei Sheng");
	m.addStudent("Yohanes Yudhi Adhikusuma");
	m.addStudent("Srivastava Aaryam");
	m.printClassRoster();
	m.addStudent("Steven Halim");
	m.printClassRoster();
	m.dropStudent("Yohanes Yudhi Adhikusuma");
	m.dropStudent("Sidhant Bansal");
	m.printClassRoster();
	
	return 0;
}

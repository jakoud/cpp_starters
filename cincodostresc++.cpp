#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
	fstream cos;
	cos.open("kotek.txt", ios::in);
	if(!cos.good()){
		cout<<"blad";
		return 0;
	}
	string napis, nap, s;
	getline(cos, napis);
	cout<<napis<<endl;
	nap="ale mi sie";
	s=nap+' '+"nie chce";
	cout<<s<<endl;
	for(int i=0;i<s.size();++i)
		cout<<s[i];
	cout<<endl;
	for(string::iterator i=s.begin();i<s.end();++i)
		cout<<*i;
	cout<<endl;

	//cos<<"jakies konkretne zdanie";

	cos.close();
	return 0;
}

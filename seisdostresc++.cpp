#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>
#include <string>

using namespace std;

template<class Typ>

void sortList_scalanie(list<Typ> &G){
	if(G.size()>1){
		typename list<Typ>::iterator i=G.begin(), j;
		for (int k=G.size()/2; k>0;--k)
			++i;
		list<Typ> poczatek;
		poczatek.splice(poczatek.begin(), G, G.begin(), i);
		sortList_scalanie<Typ>(poczatek);
		sortList_scalanie<Typ>(G);
		i=G.begin();
		j=poczatek.begin();
		while(i!=G.end() && j!=poczatek.end()){
			if(*i<*j){
				++i;
			}
			else{
				G.splice(i, poczatek, j);
				j=poczatek.begin();
			}
		}
		if(poczatek.size()>0){
			G.splice(G.end(), poczatek);
		}
	}
}


 int main(){
 	srand(time(NULL));
 	int n;
 	cout<<"ile wyrazow chcesz?: ";
 	cin>>n;

 	list<string> L;
 	list<int> Inty;
 	string wyraz;
 	cout<<"podaj wyrazy: "<<endl;

 	for (;n>0;--n){
		cin>>wyraz;
		L.push_back(wyraz);
		Inty.push_back(rand()%101);
 	}

 	for (list<string>::iterator i=L.begin(); i!=L.end(); ++i){
		cout<<*i<<endl;
 	}
 	cout<<endl;
 	for (list<int>::iterator i=Inty.begin(); i!=Inty.end(); ++i){
		cout<<*i<<' ';
 	}
 	cout<<endl;
	sortList_scalanie<string>(L);
	sortList_scalanie<int>(Inty);

 	for (list<string>::iterator i=L.begin(); i!=L.end(); ++i){
		cout<<*i<<endl;
 	}
 	cout<<endl;
 	for (list<int>::iterator i=Inty.begin(); i!=Inty.end(); ++i){
		cout<<*i<<' ';
 	}
 	cout<<endl;

 return 0;
 }

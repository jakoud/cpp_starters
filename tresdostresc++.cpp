#include <iostream>

using namespace std;

class przyklad{
		int rozmiar;
		float *tablica;
	public:
		przyklad(int roz=1):rozmiar(roz){
         tablica=new float(rozmiar);
		}
	friend ostream& operator<<(ostream&, const przyklad&);
	friend istream& operator>>(istream&, przyklad&);
	~przyklad(){
		delete[] tablica;
	}
};

int main(){
	przyklad tab(4), ww(2);
	cin>>tab;
	cout<<tab<<endl<<ww;
	ww=tab;
	cout<<endl<<tab<<endl<<ww;
	cin>>ww;
	cout<<endl<<tab<<endl<<ww;

return 0;
}

ostream& operator<<(ostream &out, const przyklad &nasz){
	for (int i=0; i<nasz.rozmiar; ++i)
		out<<nasz.tablica[i]<<", ";
	return out;
}
istream& operator>>(istream &in, przyklad &nasz){
	for(int i=0; i<nasz.rozmiar;++i)
		in>>nasz.tablica[i];
	return in;
}

#include<iostream>
#define ROZMIAR 10
using namespace std;
void wypisz(int A[], int n, int p, int k)
{
	for(int i=0;i<n;i++)
		cout<<A[i];
	cout<<"	p="<<p<<"	k="<<k;
	cout<<endl;
}

class kolejka
{
	int poczatek, koniec;
	int tab[ROZMIAR];
	public:
		kolejka();
		kolejka(int i);	// konstruuje pocz¹tkow¹ kolejkê z zadania z egzaminu
		int pusta();
		void wstaw(int x);
		int zwroc();
		void usun();
};
// pusta kiedy poczatek=koniec
// pe³na kiedy poczatek=koniec+1
// poczatek wstazuje NA element, koniec ZA element
kolejka::kolejka()
{
	poczatek=0;
	koniec=0;
}
kolejka::kolejka(int i)
{
	int A[10]={4,9,3,7,0,3,1,8,7,5};
	for(int a=0;a<10;a++)
		tab[a]=A[a];
	poczatek=9;
	koniec=1;
	wypisz(tab,ROZMIAR,poczatek,koniec);
}
int kolejka::pusta()
{
	if(poczatek==koniec)
		return 1;
	return 0;
}
void kolejka::wstaw(int x)
{
	if((koniec+1)%ROZMIAR!=poczatek)	// kolejka nie jest pe³na
	{
		tab[koniec]=x;
		koniec=(koniec+1)%ROZMIAR;
	}
	wypisz(tab,ROZMIAR,poczatek,koniec);
}
int kolejka::zwroc()
{
	if(!pusta())
		return tab[poczatek];
}
void kolejka::usun()
{
	if(!pusta())
		poczatek=(poczatek+1)%ROZMIAR;
	wypisz(tab,ROZMIAR,poczatek,koniec);
}

main()
{
	kolejka k(0);
	k.wstaw(7);
	cout<<k.zwroc()<<endl;
	k.usun();
	k.usun();
	k.usun();
	k.usun();
	k.wstaw(2);
	k.wstaw(1);
	k.usun();
	cout<<k.zwroc();
}

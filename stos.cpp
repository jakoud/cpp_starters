#include<iostream>
#define ROZMIAR 10
using namespace std;
void wypisz(int A[], int n, int s)
{
	for(int i=0;i<n;i++)
		cout<<A[i];
	cout<<"	s="<<s;
	cout<<endl;
}

class stos
{
	int szczyt;
	int tab[ROZMIAR];
	public:
		stos();
		stos(int i);	// konstruuje pocz¹tkowy stos z zadania z egzaminu
		int pusty();
		void wstaw(int x);
		int zwroc();
		void usun();
};
stos::stos()
{
	szczyt=-1;
}
stos::stos(int i)
{
	int A[10]={4,9,3,7,0,3,1,8,7,5};
	for(int a=0;a<10;a++)
		tab[a]=A[a];
	szczyt=1;
	wypisz(tab,ROZMIAR,szczyt);
}
int stos::pusty()
{
	if(szczyt==-1)
		return 1;
	return 0;
}
void stos::wstaw(int x)
{
	if(szczyt<ROZMIAR-1)
	{
		szczyt++;
		tab[szczyt]=x;
	}
	wypisz(tab,ROZMIAR,szczyt);
}
int stos::zwroc()
{
	if(!pusty())
		return tab[szczyt];
}
void stos::usun()
{
	if(!pusty())
		szczyt--;
	wypisz(tab,ROZMIAR,szczyt);
}

main()
{
	stos s(0);
	s.wstaw(9);
	cout<<s.zwroc()<<endl;
	s.usun();
	s.usun();
	s.usun();
	s.usun();
	s.wstaw(2);
	s.wstaw(1);
	s.usun();
	cout<<s.zwroc();
}

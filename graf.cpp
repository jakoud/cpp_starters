#include<iostream>
#define MAX 10
using namespace std;
int odwiedzony[MAX];

// #include "kolejka.h"
class kolejka
{
	int poczatek, koniec;
	int tab[100];
	public:
		kolejka();
		int pusta();
		void wstaw(int x);
		int zwroc();
		void usun();
};
kolejka::kolejka()
{
	poczatek=0;
	koniec=0;
}
int kolejka::pusta()
{
	if(poczatek==koniec)
		return 1;
	return 0;
}
void kolejka::wstaw(int x)
{
	if((koniec+1)%100!=poczatek)
	{
		tab[koniec]=x;
		koniec=(koniec+1)%100;
	}
}
int kolejka::zwroc()
{
	if(!pusta())
		return tab[poczatek];
}
void kolejka::usun()
{
	if(!pusta())
		poczatek=(poczatek+1)%100;
}

// #include "stos.h"
class stos
{
	int szczyt;
	int tab[100];
	public:
		stos();
		int pusty();
		void wstaw(int x);
		int zwroc();
		void usun();
};
stos::stos()
{
	szczyt=-1;
}
int stos::pusty()
{
	if(szczyt==-1)
		return 1;
	return 0;
}
void stos::wstaw(int x)
{
	if(szczyt<100-1)
	{
		szczyt++;
		tab[szczyt]=x;
	}
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
}

class graf
{
	int n;
	int A[MAX][MAX];
	public:
		graf();
		void przyklad();
		int LiczbaWierzcholkow();
		int LiczbaKrawedzi();
		int Stopien(int w);
		int MaksymalnyStopien();
		int MinimalnyStopien();
		void przegladanie_wglab();
		void DFS(int w);
		void DFS_bez_wypisywania(int w);
		int spojny();
		int LiczbaSkladowychSpojnych();
		void WypiszSkladoweSpojne();
		void przegladanie_wszerz();
		void BFS(int w);
		void cykl_Eulera();
		int eulerowski();
};
graf::graf()
{
	n=0;
	for(int i=0;i<MAX;i++)
	{
		for(int j=0;j<MAX;j++)
			A[i][j]=0;
	}
}
void graf::przyklad()
{
	n=9;
	A[0][1]=1;
	A[0][4]=1;
	A[1][0]=1;
	A[1][2]=1;
	A[1][4]=1;
	A[1][6]=1;
	A[2][1]=1;
	A[2][3]=1;
	A[2][4]=1;
	A[2][5]=1;
	A[3][2]=1;
	A[3][4]=1;
	A[3][5]=1;
	A[3][7]=1;
	A[4][0]=1;
	A[4][1]=1;
	A[4][2]=1;
	A[4][3]=1;
	A[4][5]=1;
	A[4][6]=1;
	A[4][7]=1;
	A[4][8]=1;
	A[5][2]=1;
	A[5][3]=1;
	A[5][4]=1;
	A[5][6]=1;
	A[6][1]=1;
	A[6][4]=1;
	A[6][5]=1;
	A[6][7]=1;
	A[7][3]=1;
	A[7][4]=1;
	A[7][6]=1;
	A[7][8]=1;
	A[8][4]=1;
	A[8][7]=1;
}
int graf::LiczbaWierzcholkow()
{
	return n;
}
int graf::LiczbaKrawedzi()
{
	int licznik=0;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
			licznik=licznik+A[i][j];
	}
	return licznik;
}
int graf::Stopien(int w)
{
	int licznik=0;
	for(int i=0;i<n;i++)
		licznik=licznik+A[w][i];
	return licznik;
}
int graf::MaksymalnyStopien()
{
	int max=Stopien(0);
	for(int i=1;i<n;i++)
	{
		if(Stopien(i)>max)
			max=Stopien(i);
	}
	return max;
}
int graf::MinimalnyStopien()
{
	int min=Stopien(0);
	for(int i=1;i<n;i++)
	{
		if(Stopien(i)<min)
			min=Stopien(i);
	}
	return min;
}
void graf::przegladanie_wglab()
{
	for(int i=0;i<n;i++)
		odwiedzony[i]=0;
	for(int i=0;i<n;i++)
	{
		if(odwiedzony[i]==0)
			DFS(i);
	}
}
void graf::DFS(int w)
{
	odwiedzony[w]=1;
	cout<<w<<", ";
	for(int i=0;i<n;i++)
	{
		if(A[i][w]==1 && odwiedzony[i]==0)
			DFS(i);
	}
}
void graf::DFS_bez_wypisywania(int w)
{
	odwiedzony[w]=1;
	for(int i=0;i<n;i++)
	{
		if(A[i][w]==1 && odwiedzony[i]==0)
			DFS_bez_wypisywania(i);
	}
}
int graf::spojny()
{
	if(LiczbaSkladowychSpojnych()==1)
		return 1;
	return 0;
}
int graf::LiczbaSkladowychSpojnych()
{
	for(int i=0;i<n;i++)
		odwiedzony[i]=0;
	int licznik=0;
	for(int i=0;i<n;i++)
	{
		if(odwiedzony[i]==0)
		{
			licznik++;
			DFS_bez_wypisywania(i);
		}
	}
	return licznik;
}
void graf::WypiszSkladoweSpojne()
{
	for(int i=0;i<n;i++)
		odwiedzony[i]=0;
	int licznik=0;
	for(int i=0;i<n;i++)
	{
		if(odwiedzony[i]==0)
		{
			licznik++;
			cout<<"skladowa "<<licznik<<": ";
			DFS(i);
			cout<<endl;
		}
	}
}
void graf::przegladanie_wszerz()
{
	for(int i=0;i<n;i++)
		odwiedzony[i]=0;
	for(int i=0;i<n;i++)
	{
		if(odwiedzony[i]==0)
			BFS(i);
	}
}
void graf::BFS(int w)
{
	kolejka k;
	odwiedzony[w]=1;
	k.wstaw(w);
	while(!k.pusta())
	{
		w=k.zwroc();
		k.usun();
		cout<<w<<", ";
		for(int i=0;i<n;i++)
		{
			if(A[w][i]==1 && odwiedzony[i]==0)
			{
				odwiedzony[i]=1;
				k.wstaw(i);
			}
		}
	}
}
void graf::cykl_Eulera()
{
	if(eulerowski())
	{
		stos s;
		stos wynik;
		s.wstaw(0);
		while(!s.pusty())
		{
			int v=s.zwroc();
			int i;
			for(i=0;i<n;i++)
			{
				if(A[v][i]==1)
				{
					s.wstaw(i);
					A[v][i]=0;
					A[i][v]=0;
					break;
				}
			}
			if(i==n)
			{
				s.usun();
				wynik.wstaw(v);
			}
		}
		// Wypisanie wyniku
		while(!wynik.pusty())
		{
			cout<<wynik.zwroc()<<", ";
			wynik.usun();
		}
	}
}
int graf::eulerowski()
{
	if(!spojny())
		return 0;
	for(int i=0;i<n;i++)
	{
		if(Stopien(i)%2!=0)
			return 0;
	}
	return 1;
}
main()
{
	graf G;
	G.przyklad();
	G.przegladanie_wglab();
	cout<<endl;
	G.przegladanie_wszerz();
	cout<<endl;
	G.cykl_Eulera();
}

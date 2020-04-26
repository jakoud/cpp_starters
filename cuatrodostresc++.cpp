#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void sort_szybkie(int *, int);
void sort_szybkie_wlasciwe(int *, int, int);
void sort_kopcowanie(int*, int);

int main(){
	srand(time(NULL));
	int a=-12, b=18;
	int tablica[25];
	for(int i=0;i<25;++i)
		tablica[i]=rand()%(b-a+1)+a;
	for(int i=0;i<25;++i)
		cout<<tablica[i]<<' ';
	sort_szybkie(tablica, 25);
	cout<<endl;
	for(int i=0;i<25;++i)
		cout<<tablica[i]<<' ';
	sort_kopcowanie(tablica, 25);
	cout<<endl;
	for(int i=0;i<25;++i)
		cout<<tablica[i]<<' ';



	return 0;
}
 void sort_szybkie(int *tab, int n){
	sort_szybkie_wlasciwe(tab, 0, n-1);
	}
void sort_szybkie_wlasciwe(int *tab, int lewy, int prawy){
	int pivot=tab[(lewy+prawy)/2];
	int x=lewy, y=prawy;
	while(x<=y){
		while(tab[x]<pivot) ++x;
		while(pivot<tab[y]) --y;
	if (x<=y){
		swap(tab[x], tab[y]);
		++x;
		--y;
	}
	if(lewy<y)
		sort_szybkie_wlasciwe(tab, lewy, y);
	if(x<prawy)
		sort_szybkie_wlasciwe(tab, x, prawy);
}
}

void sort_kopcowanie(int *tab, int n){
	int i, badany, ojciec;
	for (i=1;i<=n; ++i){
		badany=i;
		ojciec=badany/2;
		while(ojciec>0 && tab[badany-1]>tab[ojciec-1]){
			swap(tab[badany-1], tab[ojciec-1]);
			badany=ojciec;
			ojciec=badany/2;
		}
	}
	int syn;
	for(i=n;i>0;--i){
		swap(tab[1-1],tab[i-1]);
		badany=1;
		syn=2*badany;
		while(syn<i){
			if(syn+1<i && tab[syn-1]<tab[syn+1-1]){
				++syn;
			}
			if(tab[syn-1]>tab[badany-1]){
				swap(tab[syn-1], tab[badany-1]);
				badany=syn;
				syn=2*badany;
			}
			else break;
		}
	}
}
